/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:22:15 by banthony          #+#    #+#             */
/*   Updated: 2017/10/04 19:22:16 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		page_type(t_page *p, char type)
{
	if (p->tag[TYPE] != type)
		return ;
	show_malloc_type(type);
	ft_print_ptr(&p->tag[DATA]);
	ft_putchar('\n');
}

static size_t	display_detail(t_page *p, size_t is_ex)
{
	size_t	s;
	t_mdata	*d;

	s = 0;
	if (!p)
		return (0);
	d = (void*)&p->tag[DATA];
	while (d)
	{
		if (d->tag[STATE] != EMPTY)
		{
			ft_print_ptr((void*)&d->tag[DATA]);
			ft_putstr(" - ");
			ft_print_ptr((void*)(char*)(&d->tag[DATA] + d->size));
			ft_putstr(" : ");
			ft_putnbr((long long)d->size);
			ft_putendl(" octets");
			if (is_ex)
				show_dump_hex((void*)&d->tag[DATA], d->size);
			s += d->size;
		}
		d = d->next;
	}
	return (s);
}

static void		alloc_of_type(t_page *p, char type, size_t *total, size_t is_ex)
{
	size_t	s;

	s = 0;
	while (p)
	{
		if (p->tag[TYPE] == type)
		{
			page_type(p, type);
			s = display_detail(p, is_ex);
			*total = *total + s;
		}
		p = p->next;
	}
}

void			show_alloc_mem(void)
{
	char	type;
	size_t	total;
	t_page	*p;

	if (!g_mem || !(p = (t_page*)g_mem))
	{
		ft_putendl("Empty Memory");
		return ;
	}
	total = 0;
	type = TINY - 1;
	while (++type <= LARGE)
	{
		p = (t_page*)g_mem;
		alloc_of_type(p, type, &total, 0);
	}
	ft_putstr("Total : ");
	ft_putnbr((long long)total);
	ft_putstr(" octets\n");
}

void			show_alloc_mem_ex(void)
{
	char	type;
	size_t	total;
	t_page	*p;

	if (!g_mem || !(p = (t_page*)g_mem))
	{
		ft_putendl("Empty Memory");
		return ;
	}
	total = 0;
	type = TINY - 1;
	while (++type <= LARGE)
	{
		p = (t_page*)g_mem;
		alloc_of_type(p, type, &total, 1);
	}
	ft_putstr("Total : ");
	ft_putnbr((long long)total);
	ft_putstr(" octets\n");
}
