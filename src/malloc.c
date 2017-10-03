/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:09:11 by banthony          #+#    #+#             */
/*   Updated: 2017/10/03 14:49:33 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void *g_mem = NULL;

t_page			*new_page(t_page *page, size_t s)
{
	t_page	*b;
	t_mdata	*p;
	size_t	n;

	n = get_limit(s);
	if (!(b = mmap(NULL, (PAGE_S + n),
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	ft_memset(b, 0, PAGE_S + n);
	b->size = n;
	b->tag[STATE] = PARTIAL;
	b->tag[TYPE] = get_malloc_type(n);
	if (b->size == s)
		b->tag[STATE] = FULL;
	ft_strncpy(&b->tag[2], END_PAGE, 6);
	p = (void*)&b->tag[DATA];
	p->size = s;
	p->tag[STATE] = FULL;
	ft_strncpy(&p->tag[2], END_DATA, 6);
	if (!page)
		return (b);
	while (page->next)
		page = page->next;
	page->next = b;
	b->prev = page;
	return (b);
}

static t_mdata	*fill_mdata(t_page *p, t_mdata *d)
{
	t_mdata	*tmp;
	size_t	reserved;

	reserved = 0;
	tmp = (void*)&p->tag[DATA];
	while (tmp)
	{
		reserved += tmp->size + MDATA_S;
		tmp = tmp->next;
	}
	if (p->size == reserved)
		p->tag[STATE] = FULL;
	d->tag[STATE] = FULL;
	return (d);
}

static t_mdata	*add_mdata(t_page *p, t_mdata *last, size_t reserved, size_t s)
{
	t_mdata	*d;

	if (!p || !last)
		return (NULL);
	d = (void*)((char*)&last->tag[DATA] + last->size);
	d->size = s;
	d->tag[STATE] = FULL;
	last->next = d;
	d->next = NULL;
	if (p->size == (reserved + MDATA_S + s))
		p->tag[STATE] = FULL;
	ft_strncpy(&d->tag[2], END_DATA, 6);
	return (d);
}

t_mdata			*find_space(t_page *p, size_t s)
{
	t_mdata	*last;
	t_mdata	*d;
	size_t	reserved;

	if (!p)
		return (NULL);
	reserved = 0;
	last = NULL;
	d = (void*)&p->tag[DATA];
	while (d)
	{
		reserved += (d->size + MDATA_S);
		if (d->tag[STATE] == EMPTY)
		{
			if (d->size > (s + MDATA_S + DATA_MIN))
				return (split_block(d, s));
			if (d->size >= s)
				return (fill_mdata(p, d));
		}
		last = d;
		d = d->next;
	}
	if (p->size >= (reserved + MDATA_S + s))
		d = add_mdata(p, last, reserved, s);
	return (d);
}

void			*malloc(size_t size)
{
	t_page	*p;
	t_mdata	*tmp;

	if (size <= 0)
		return (NULL);
	if (!g_mem)
	{
		if (!(p = new_page(NULL, ALIGN(size))))
			return (NULL);
		g_mem = p;
	}
	else
	{
		p = g_mem;
		if (!(tmp = get_free_mem(p, ALIGN(size))))
		{
			if (!(p = new_page(p, ALIGN(size))))
				return (NULL);
		}
		else
			return ((void*)&tmp->tag[DATA]);
	}
	return ((void*)((char*)&p->tag[DATA] + MDATA_S));
}
