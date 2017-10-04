/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_ex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 13:09:39 by banthony          #+#    #+#             */
/*   Updated: 2017/10/04 19:20:43 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t	get_size_area(size_t s)
{
	if (s == TINY_LIMIT)
		return (N);
	if (s == SMALL_LIMIT)
		return (M);
	return (ALIGN_PSIZE(s + PAGE_S));
}

char	get_malloc_tag_type(size_t s)
{
	if (s <= TINY_LIMIT)
		return (TINY);
	if (s <= SMALL_LIMIT && s > TINY_LIMIT)
		return (SMALL);
	return (LARGE);
}

void	show_malloc_type(char type)
{
	if (type == TINY)
		ft_putstrcol(GREEN, "TINY");
	if (type == SMALL)
		ft_putstrcol(YELLOW, "SMALL");
	if (type == LARGE)
		ft_putstrcol(RED, "LARGE");
	ft_putstr(" : ");
}

void	show_dump_hex(void *ptr, size_t size)
{
	ft_putstr(BLUE);
	ft_print_memory(ptr, size);
	ft_putstr(WHITE);
	ft_putchar('\n');
}
