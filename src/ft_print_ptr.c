/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 13:19:19 by banthony          #+#    #+#             */
/*   Updated: 2017/10/03 14:30:42 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_print_ptr(void *addr)
{
	unsigned char	*adr;
	size_t			size;
	size_t			n;

	size = sizeof(addr);
	adr = (unsigned char*)&addr;
	n = 5;
	ft_putstr("0x");
	while (n <= size)
	{
		ft_putchar_base(adr[size - n], 16, "0123456789abcdef");
		n++;
	}
}
