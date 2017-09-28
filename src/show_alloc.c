/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:01:38 by banthony          #+#    #+#             */
/*   Updated: 2017/09/28 18:23:02 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	get_malloc_type(t_page *p)
{
	ft_putstrcol(BLUE, "MALLOC TYPE: ");
	if (p->size <= TINY_LIMIT)
		ft_putstrcol(GREEN, "TINY\n");
	if (p->size <= SMALL_LIMIT && p->size > TINY_LIMIT)
		ft_putstrcol(YELLOW, "SMALL\n");
	if (p->size > SMALL_LIMIT)
		ft_putstrcol(RED, "LARGE\n");
}

static void	get_page_type(t_page *p)
{
	ft_putstrcol(BLUE, "Taille de la page: ");
	ft_putstr(GREEN);
	ft_putnbrendl((int)p->size);
	ft_putstrcol(BLUE, "Page STATE: ");
	if (p->tag[STATE] == PARTIAL)
		ft_putstrcol(YELLOW, "PARTIAL\n");
	if (p->tag[STATE] == FULL)
		ft_putstrcol(RED, "FULL\n");
	if (p->tag[STATE] == EMPTY)
		ft_putstrcol(GREEN, "EMPTY\n");
}

static void	get_data_detail(t_page *p)
{
	t_mdata	*tmp;
	size_t	nb;
	size_t	free;

	tmp = (void*)&p->tag[DATA];
	nb = get_nb_block(p, BLOCK);
	free = get_nb_block(p, EMPTY);
	ft_putstrcol(BLUE, "Total Block: ");
	ft_putstr(GREEN);
	ft_putnbrendl((int)nb);
	ft_putstrcol(BLUE, "Reserve: ");
	ft_putstr(GREEN);
	ft_putnbrendl((int)(nb - free));
	ft_putstrcol(BLUE, "Libres: ");
	ft_putstr(GREEN);
	ft_putnbrendl((int)free);
	ft_putstr(WHITE);
}

void		show_alloc_mem_ex(void)
{
	t_page *p;

	if (!g_mem || !(p = (t_page*)g_mem))
	{
		ft_putstrcol(BLUE, "Empty Memory\n");
		return ;
	}
	while (p)
	{
		get_page_type(p);
		get_malloc_type(p);
		get_data_detail(p);
		ft_print_memory(p, (p->size + PAGE_S));
		p = p->next;
	}
}
