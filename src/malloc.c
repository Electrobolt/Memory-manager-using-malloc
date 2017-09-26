/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:09:11 by banthony          #+#    #+#             */
/*   Updated: 2017/09/26 20:25:19 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*mem = NULL;
char	endpage[6] = "PAGE->";
char	enddata[6] = "DATA->";

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

t_page	*new_page(t_page *page, size_t s)
{
	t_page	*b;
	t_mdata	*p;
	size_t	n;

	n = get_limit(s);
	if (!(b = mmap(NULL, (sizeof(t_page) + n), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	ft_memset(b, 0, sizeof(t_page) + n);
	b->size = n;
	b->tag[STATE] = PARTIAL;
	if (b->size == s)
		b->tag[STATE] = FULL;
	ft_strncpy(&b->tag[2], endpage, 6);// provisoire
	p = (void*)&b->tag[DATA];
	p->size = s;
	p->tag[STATE] = FULL;
	ft_strncpy(&p->tag[2], enddata, 6);//provisoire
	if (page)
	{
		while (page->next)
			page = page->next;
		page->next = b;
	}
	return (b);
}

t_mdata	*find_space(t_page *p, size_t s)
{
	t_mdata *tmp;
	t_mdata	*last;
	size_t	reserved;

	reserved = 0;
	last = NULL;
	if (!p)
		return (NULL);
	tmp = (void*)&p->tag[DATA];
	while (tmp->next)
	{
		reserved += (tmp->size + sizeof(t_mdata));
		tmp = tmp->next;
	}
	reserved += (tmp->size + sizeof(t_mdata));
	if (p->size >= (reserved + sizeof(t_mdata) + s))
	{
		last = (void*)((char*)&tmp->tag[DATA] + tmp->size);
		last->next = NULL;
		last->size = s;
		last->tag[STATE] = FULL;
		if (p->size == (reserved + sizeof(t_mdata) + s))
			p->tag[STATE] = FULL;
		tmp->next = last;
		ft_strncpy(&last->tag[2], enddata, 6);
	}
	return (last);
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

	if (!mem)	// Premier appel
	{
		if (!(p = new_page(NULL, align(size))))
			return (NULL);
		mem = p;
	}
	else
	{
		p = mem;
		if (!(tmp = get_free_mem(p, align(size))))
		{
			if (!(p = new_page(p, align(size))))
				return (NULL);
		}
		else
			return ((void*)&tmp->tag[DATA]);
	}
	return ((void*)((char*)&p->tag[DATA] + sizeof(t_mdata)));
}
