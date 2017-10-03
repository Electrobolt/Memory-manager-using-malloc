/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 14:39:40 by banthony          #+#    #+#             */
/*   Updated: 2017/10/03 14:32:24 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_putchar_base(unsigned char c, unsigned int base, char *tab)
{
	if (!tab || !base)
		return ;
	ft_putchar(tab[c / base]);
	ft_putchar(tab[c % base]);
}
