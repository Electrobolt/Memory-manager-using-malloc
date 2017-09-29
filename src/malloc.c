/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:09:11 by banthony          #+#    #+#             */
/*   Updated: 2017/09/29 12:22:29 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void *g_mem = NULL;
char g_endpage[6] = "PAGE->";
char g_enddata[6] = "DATA->";

t_page	*new_page(t_page *page, size_t s)
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
	if (b->size == s)
		b->tag[STATE] = FULL;
	ft_strncpy(&b->tag[2], g_endpage, 6);// provisoire
	p = (void*)&b->tag[DATA];
	p->size = s;
	p->tag[STATE] = FULL;
	ft_strncpy(&p->tag[2], g_enddata, 6);//provisoire
	if (page)
	{
		while (page->next)
			page = page->next;
		page->next = b;
		b->prev = page;
	}
	return (b);
}

static t_mdata	*fill_block(t_page *p, t_mdata *d)
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

t_mdata	*find_space(t_page *p, size_t s)
{
	t_mdata *last;
	t_mdata *d;
	size_t reserved;

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
			if (d->size == s || d->size >= (s + DATA_MIN))
				return (fill_block(p, d));
		}
		last = d;
		d = d->next;
	}
	if (p->size >= (reserved + MDATA_S + s))
	{
		d = (void*)((char*)&last->tag[DATA] + last->size);
		d->size = s;
		d->tag[STATE] = FULL;
		last->next = d;
		d->next = NULL;
		if (p->size == (reserved + MDATA_S + s))
			p->tag[STATE] = FULL;
		ft_strncpy(&d->tag[2], g_enddata, 6);//provisoire
	}
	return (d);
}

t_mdata	*split_block(t_mdata *d, size_t s)
{
	t_mdata *new;

	new = (void*)((char*)&d->tag[DATA] + s);
	new->size = (d->size - (MDATA_S +  s));
	new->tag[STATE] = EMPTY;
	new->next = d->next;
	d->next = new;
	d->size = s;
	d->tag[STATE] = FULL;
	ft_strncpy(&new->tag[2], g_enddata, 6);//provisoire
	return (d);
}

t_mdata	*get_free_mem(t_page *p, size_t s)
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

void	*my_malloc(size_t size)
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
