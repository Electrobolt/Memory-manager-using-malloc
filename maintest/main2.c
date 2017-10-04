/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:19:51 by banthony          #+#    #+#             */
/*   Updated: 2017/10/04 20:17:35 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/*
**	Test de la defragmentation
*/
int main(void)
{
	char *str1, *str2, *str3, *str4, *str5, *str6;
	int i = 0;

	str1 = (char*)malloc(sizeof(char) * 32);
	str2 = (char*)malloc(sizeof(char) * 32);
	str3 = (char*)malloc(sizeof(char) * 32);
	str4 = (char*)malloc(sizeof(char) * 32);
	i = 0;
	while (i < 32)
	{
		strncpy(&str1[i], "1", 1);
		strncpy(&str2[i], "2", 1);
		strncpy(&str3[i], "3", 1);
		strncpy(&str4[i], "4", 1);
		i++;
	}
	ft_putstr("-------------Show_mem_ex1--------------\n");
	show_alloc_mem_ex();
	ft_putstr("-------------Show_mem1-----------------\n");
	show_alloc_mem();
	free(str3);
	free(str4);
	str5 = (char*)malloc(sizeof(char) * 64);
	i = 0;
	while (i < 64)
	{
		strncpy(&str5[i], "5", 1);
		i++;
	}
	ft_putstr("-------------Show_mem_ex2--------------\n");
	show_alloc_mem_ex();
	ft_putstr("-------------Show_mem2-----------------\n");
	show_alloc_mem();
	free(str2);
	free(str1);
	str6 = (char*)realloc(str5, 128);
	i = 0;
	while (i < 128)
	{
		strncpy(&str5[i], "6", 1);
		i++;
	}
	ft_putstr("-------------Show_mem_ex3--------------\n");
	show_alloc_mem_ex();
	ft_putstr("-------------Show_mem3-----------------\n");
	show_alloc_mem();

}



















