/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 14:39:40 by banthony          #+#    #+#             */
/*   Updated: 2017/10/03 14:33:11 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	print_char(unsigned char *adr, size_t i, size_t size)
{
	size_t	n;
	size_t	max;

	n = i;
	max = i + 16;
	while (n < max)
	{
		if (n < size)
		{
			if (adr[n] > 31 && adr[n] < 127)
				ft_putchar((char)adr[n]);
			else
				ft_putchar('.');
		}
		n++;
	}
}

static void	print_hex(unsigned char *adr, size_t i, size_t size)
{
	size_t	n;

	n = i;
	while (n < i + 16)
	{
		if (n < size)
			ft_putchar_base(adr[n], 16, "0123456789abcdef");
		else
			ft_putstr("  ");
		if ((n % 2))
			ft_putchar(' ');
		n++;
	}
}

void		ft_print_memory(void *addr, size_t size)
{
	unsigned char	*adr;
	size_t			i;

	adr = (unsigned char*)addr;
	i = 0;
	while (i < size)
	{
		print_hex(adr, i, size);
		print_char(adr, i, size);
		ft_putchar('\n');
		i += 16;
	}
}
