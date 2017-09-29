/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:17:08 by banthony          #+#    #+#             */
/*   Updated: 2017/09/29 14:49:59 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**  Fusionner les metadata vide
**  Toujours garder le premier bloc mdata (auquel cas data->tag[STATE] == EMPTY)
**  Si Un block est EMPTY, verifier si le block suivant l'est aussi
**  Si oui, fusion des deux,
**  Si une page passe a EMPTY, Relink la Liste en sautant la page
**  Liberer la page avec munmap
*/

t_mdata		*get_free_mem(t_page *p, size_t s)
{
	t_mdata	*last;
	t_page	*page;
	size_t	lim;

	if (!p)
		return (NULL);
	last = NULL;
	lim = get_limit(s);
	page = p;
	while (page)
	{
		if (page->size == lim && page->tag[STATE] <= PARTIAL)
			if ((last = find_space(page, s)))
				break ;
		page = page->next;
	}
	return (last);
}

static void	free_page(t_page *p)
{
	size_t	n;
	size_t	f;

	n = get_nb_block(p, BLOCK);
	f = get_nb_block(p, EMPTY);
	if (n == f)
	{
		if (p->prev)
			p->prev->next = p->next;
		if (p->next)
		{
			if (!p->prev)
				g_mem = p->next;
			p->next->prev = p->prev;
		}
		munmap(p, p->size + PAGE_S);
	}
}

void		defrag_mem(t_page *p)
{
	size_t	reserved;
	t_mdata	*last;
	t_mdata	*d;

	reserved = 0;
	last = NULL;
	d = (void*)&p->tag[DATA];
	while (d)
	{
		if (d->tag[STATE] == EMPTY && (d->next && d->next->tag[STATE] == EMPTY))
		{
			d->size += (d->next->size + MDATA_S);
			d->next = d->next->next;
			ft_memset(&d->tag[DATA], 0, d->size);
			continue ;
		}
		last = d;
		reserved += (d->size + MDATA_S);
		d = d->next;
	}
	if (p->size > reserved)
		last->size += (p->size - reserved);
	free_page(p);
}

t_mdata		*find_ptr(void *ptr, t_page **p)
{
	t_mdata	*d;

	if (!ptr || !p || !(*p = g_mem))
		return (NULL);
	d = NULL;
	while (*p)
	{
		d = (void*)&(*p)->tag[DATA];
		while (d)
		{
			if (&d->tag[DATA] == ptr)
				return (d);
			d = d->next;
		}
		*p = (*p)->next;
	}
	return (NULL);
}

void		my_free(void *ptr)
{
	t_page	*p;
	t_mdata	*d;

	p = NULL;
	if (!(d = find_ptr(ptr, &p)) || !p)
		return ;
	d->tag[STATE] = EMPTY;
	p->tag[STATE] = PARTIAL;
	ft_memset(&d->tag[DATA], 0, d->size);
	defrag_mem(p);
}
