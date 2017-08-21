/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:19:51 by banthony          #+#    #+#             */
/*   Updated: 2017/08/21 19:28:37 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *str, *str2;

	str = (char*)malloc(sizeof(char) * 8);
	str2 = (char*)malloc(sizeof(char) * 16);
	ft_memset((void*)str, '\0', 8);
	ft_memset((void*)str2, '-', 16);
	ft_print_memory(str, 64);
	printf("malloc:%lu - %p - %d - ZONE:%d - CACHE_STATE %d\n", sizeof(str), (void*)str, getpagesize(), LARGE, PARTIAL);
	while (42)
		;
}



















