/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 13:03:06 by banthony          #+#    #+#             */
/*   Updated: 2017/10/03 17:14:39 by banthony         ###   ########.fr       */
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

static size_t	display_detail(t_page *p)
{
	size_t	s;
	t_mdata	*d;

	s = 0;
	if (!p)
		return (0);
	d = (void*)&p->tag[DATA];
	while (d)
	{
		ft_print_ptr((void*)&d->tag[DATA]);
		ft_putstr(" - ");
		ft_print_ptr((void*)(char*)(&d->tag[DATA] + d->size));
		ft_putstr(" : ");
		ft_putnbr((long long)d->size);
		ft_putendl(" octets");
		s += d->size;
		d = d->next;
	}
	return (s);
}

static void		alloc_of_type(t_page *p, char type, size_t *total)
{
	size_t	s;

	s = 0;
	while (p)
	{
		page_type(p, type);
		if (p->tag[TYPE] == type)
		{
			s = display_detail(p);
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
		alloc_of_type(p, type, &total);
	}
	ft_putstr("Total : ");
	ft_putnbr((long long)total);
	ft_putstr(" octets\n");
}
