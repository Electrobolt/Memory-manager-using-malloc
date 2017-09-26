/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:01:38 by banthony          #+#    #+#             */
/*   Updated: 2017/09/26 21:48:24 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void get_malloc_type(t_page *p)
{
	ft_putstrcol(BLUE, "MALLOC TYPE: ");
	if (p->size <= TINY_LIMIT)
		ft_putstrcol(GREEN,"TINY\n");
	if (p->size <= SMALL_LIMIT && p->size > TINY_LIMIT)
		ft_putstrcol(YELLOW,"SMALL\n");
	if (p->size > SMALL_LIMIT)
		ft_putstrcol(RED,"LARGE\n");
}

static void get_page_type(t_page *p)
{
	ft_putstrcol(BLUE, "Taille de la page: ");
	ft_putstr(GREEN);
	ft_putnbrendl((int)p->size);
	ft_putstrcol(BLUE,"Page STATE: ");
	if (p->tag[STATE] == PARTIAL)
		ft_putstrcol(YELLOW,"PARTIAL\n");
	if (p->tag[STATE] == FULL)
		ft_putstrcol(RED,"FULL\n");
	if (p->tag[STATE] == EMPTY)
		ft_putstrcol(GREEN,"EMPTY\n");
}

static void get_data_detail(t_page *p)
{
	t_mdata *tmp;
	size_t n;
	size_t r;

	r = 0;
	n = 0;
	tmp = (void*)&p->tag[DATA];
	while (tmp)
	{
		n++;
		if (tmp->tag[STATE] == EMPTY)
			r++;
		tmp = tmp->next;
	}
	ft_putstrcol(BLUE, "Total Block: ");
	ft_putstr(GREEN);
	ft_putnbrendl((int)n);
	ft_putstrcol(BLUE, "Reserve: ");
	ft_putstr(GREEN);
	ft_putnbrendl((int)(n - r));
	ft_putstrcol(BLUE, "Libres: ");
	ft_putstr(GREEN);
	ft_putnbrendl((int)r);
	ft_putstr(WHITE);
}

void	show_alloc_mem_ex(void)
{
	t_page *p;

	p = (t_page*)mem;
	while(p)
	{
		get_page_type(p);
		get_malloc_type(p);
		get_data_detail(p);
		ft_print_memory(p, (p->size + sizeof(t_page)));
		p = p->next;
	}
}
