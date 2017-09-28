/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:19:01 by banthony          #+#    #+#             */
/*   Updated: 2017/09/28 18:22:56 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t	get_limit(size_t s)
{
	size_t n;

	n = 0;
	if (s <= TINY_LIMIT)
		n = TINY_LIMIT;
	if (s <= SMALL_LIMIT && s > TINY_LIMIT)
		n = SMALL_LIMIT;
	if (s > SMALL_LIMIT)
		n = s;
	return (n);
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










