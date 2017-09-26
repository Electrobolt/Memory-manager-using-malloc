/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:17:08 by banthony          #+#    #+#             */
/*   Updated: 2017/09/26 21:15:39 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

// Fusionner les metadata vide
// Toujours garder le premier bloc mdata de chaque page (auquel cas data->tag[STATE] == EMPTY)
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
				defrag_mem();
				return ;
			}
			d = d->next;
		}
		p = p->next;
	}
}
