/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:19:01 by banthony          #+#    #+#             */
/*   Updated: 2017/09/29 14:22:18 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t			get_limit(size_t s)
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

size_t			get_nb_block(t_page *p, char state)
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

static t_mdata	*fusion_mdata(t_mdata *d, size_t s)
{
	size_t	offset;
	t_mdata *target;

	if (!(target = d->next))
		return (NULL);
	if (target->tag[STATE] == EMPTY &&
			((d->size + MDATA_S + target->size) >= s))
	{
		offset = d->size;
		d->next = target->next;
		d->size += (MDATA_S + target->size);
		ft_memset((void*)&d->tag[DATA + offset], 0, (MDATA_S + target->size));
		if (d->size > (s + MDATA_S + DATA_MIN))
			return (split_block(d, s));
		return (d);
	}
	return (NULL);
}

t_mdata			*split_block(t_mdata *d, size_t s)
{
	t_mdata	*new;

	new = (void*)((char*)&d->tag[DATA] + s);
	new->size = (d->size - (MDATA_S + s));
	new->tag[STATE] = EMPTY;
	new->next = d->next;
	d->next = new;
	d->size = s;
	d->tag[STATE] = FULL;
	ft_strncpy(&new->tag[2], g_enddata, 6);
	return (d);
}

void			*my_realloc(void *ptr, size_t size)
{
	t_page	*p;
	t_mdata	*d;
	t_mdata	*fusion;
	void	*new;

	p = NULL;
	if (!ptr)
		return (my_malloc(size));
	if (!(d = find_ptr(ptr, &p)) || !p)
		return (NULL);
	if (!size)
	{
		my_free(ptr);
		return (my_malloc(DATA_MIN));
	}
	if (!(fusion = fusion_mdata(d, ALIGN(size))))
	{
		if (!(new = my_malloc(size)))
			return (ptr);
		ft_memcpy(new, ptr, d->size);
		my_free(ptr);
		return (new);
	}
	return ((void*)&fusion->tag[DATA]);
}
