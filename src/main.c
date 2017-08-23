/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:19:51 by banthony          #+#    #+#             */
/*   Updated: 2017/08/23 19:25:29 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	void *str, *str2;

	str = my_malloc(sizeof(char) * 8);
	str2 = my_malloc(sizeof(char) * 16);
	ft_memset((void*)str, '\0', 8);
	ft_memset((void*)str2, '-', 16);
	ft_print_memory(str, 64);
	printf("str: %p\nstr2: %p\n", str, str2);
}



















