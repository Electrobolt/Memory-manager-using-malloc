/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:17:08 by banthony          #+#    #+#             */
/*   Updated: 2017/09/27 16:43:49 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*  Fusionner les metadata vide
  Toujours garder le premier bloc mdata (auquel cas data->tag[STATE] == EMPTY)
  Si Un block est EMPTY, verifier si le block suivant l'est aussi
  Si oui, fusion des deux,
  Si une page passe a EMPTY, Relink la Liste en sautant la page
  Liberer la page avec munmap */

static void	free_page(t_page *p)
{
	t_page	*tmp;
	size_t	n;
	size_t	f;

	n = get_nb_block(p, BLOCK);
	f = get_nb_block(p, EMPTY);
	tmp = NULL;
	if (n == f)
	{
		if ((tmp = p->prev))
			p->prev->next = p->next;
		if ((p->next))
		{
			if (!tmp)
				tmp = p->next;
			p->next->prev = p->prev;
		}
/*
**	Important MaJ ptr glob, vers nouv tete de liste
*/
		g_mem = tmp;
		munmap(p, p->size + PAGE_S);
	}
}

size_t		get_nb_block(t_page *p, char state)
{
	t_mdata	*d;
	size_t	n;

	n = 0;
	d = (void*)&p->tag[DATA];
	while (d)
	{
		if (d->tag[STATE] == state || state == BLOCK)
			n++;
		d = d->next;
	}
	return (n);
}

void		defrag_mem(t_page *p)
{
	t_mdata	*d;

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
		d = d->next;
	}
	free_page(p);
}

void		my_free(void *ptr)
{
	t_page	*p;
	t_mdata	*d;

	if (!(p = g_mem))
		return ;
	while (p)
	{
		d = (void*)&p->tag[DATA];
		while (d)
		{
			if (&d->tag[DATA] == ptr)
			{
				d->tag[STATE] = EMPTY;
				p->tag[STATE] = PARTIAL;
				ft_memset(&d->tag[DATA], 0, d->size);
				defrag_mem(p);
				return ;
			}
			d = d->next;
		}
		p = p->next;
	}
}
