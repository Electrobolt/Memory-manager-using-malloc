/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:01:38 by banthony          #+#    #+#             */
/*   Updated: 2017/10/02 19:19:42 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

char		get_malloc_type(size_t s)
{
	if (s <= TINY_LIMIT)
		return (TINY);
	if (s <= SMALL_LIMIT && s > TINY_LIMIT)
		return (SMALL);
	return (LARGE);
}

static void	show_malloc_type(char type)
{
	if (type == TINY)
		ft_putstrcol(GREEN, "TINY");
	if (type == SMALL)
		ft_putstrcol(YELLOW, "SMALL");
	if (type == LARGE)
		ft_putstrcol(RED, "LARGE");
	ft_putstr(" : ");
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
		ft_putstrcol(BLUE, "MALLOC TYPE: ");
		get_page_type(p);
		show_malloc_type(p->tag[TYPE]);
		get_data_detail(p);
		ft_print_ptr(p);
		ft_putchar('\n');
		ft_print_memory(p, (p->size + PAGE_S));
		p = p->next;
	}
}

static void	page_type(t_page *p, char type)
{
	show_malloc_type(type);
	ft_print_ptr(&p->tag[DATA]);
	ft_putchar('\n');
}

static void alloc_of_type(t_page *p, char type, size_t *total)
{
	size_t s;

	s = 0;
	while (p)
	{
		if (p->tag[TYPE] == type)
		{
			s = get_nb_block(p, SIZE);
			ft_print_ptr((void*)&p->tag[DATA]);
			ft_putstr(" - ");
			ft_print_ptr((void*)(char*)(&p->tag[DATA] + s));
			ft_putstr(" : ");
			ft_putnbr((long long)s);
			ft_putendl(" octets");
			*total = *total + s;
		}
		p = p->next;
	}
}

void	show_alloc_mem(void)
{
	char	type;
	size_t	total;
	size_t	s;
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
//		test si type present dans les pages, si oui afficher page_type
//		affichage detail des pages si type present
	}
	ft_putstr("Total : ");
	ft_putnbr((long long)total);
	ft_putstr(" octets\n");
}












