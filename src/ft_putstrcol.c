/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrcol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 19:21:58 by banthony          #+#    #+#             */
/*   Updated: 2017/10/03 14:25:41 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_putstrcol(char *color, char *str)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(WHITE);
}
