/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:17:08 by banthony          #+#    #+#             */
/*   Updated: 2017/09/26 22:46:10 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

// Fusionner les metadata vide
// Toujours garder le premier bloc mdata de chaque page (auquel cas data->tag[STATE] == EMPTY)
// Si Un block est EMPTY, verifier si le block suivant l'est aussi
// Si oui, fusion des deux,
// Si une page passe a EMPTY, Relink la Liste en sautant la page
// Liberer la page avec munmap
/*
static	void free_page(t_page *p)
{
	t_mdata *d;
	size_t n;

	d = NULL;
	n = 0;
	while (p)
	{
		if (p->next)
			d = (void*)&p->next->tag[DATA];
		while (d)
		{
			n++;
			d = d->next;
		}
		if (n == 1)
		{
			if (p->next->next)
				p->next = p->next->next;
			munmap(p->next, p->next->size + PAGE_S);
		}
		p = p->next;
	}
}
*/
void	defrag_mem(void)
{
	t_page	*p;
	t_mdata	*d;

	if (!(p = mem))
		return ;
	while (p)
	{
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
//		free_page(p);
		p = p->next;
	}
}

void	my_free(void *ptr)
{
	t_page *p;
	t_mdata *d;

	if (!(p = mem))
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
				defrag_mem();
				return ;
			}
			d = d->next;
		}
		p = p->next;
	}
}
