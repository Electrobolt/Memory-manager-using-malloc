/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:19:51 by banthony          #+#    #+#             */
/*   Updated: 2017/10/04 15:14:59 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
	char *str1, *str2, *str3, *str5;
	char *str4, *str6;
	char *str7, *str8, *str9;
	int i = 0;

	str1 = (char*)malloc(sizeof(char) * 40);
	str2 = (char*)malloc(sizeof(char) * 40);
	str3 = (char*)malloc(sizeof(char) * 40);
	i = 0;
	while (i < 40)
	{
		strncpy(&str1[i], "1", 1);
		strncpy(&str2[i], "2", 1);
		strncpy(&str3[i], "3", 1);
		i++;
	}
	str4 = (char*)malloc(sizeof(char) * 40);
	str5 = (char*)malloc(sizeof(char) * 40);
	str6 = (char*)malloc(sizeof(char) * 40);
	str7 = (char*)malloc(sizeof(char) * 40);
	str8 = (char*)malloc(sizeof(char) * 40);
	i = 0;
	while (i < 40)
	{
		strncpy(&str4[i], "4", 1);
		strncpy(&str5[i], "5", 1);
		strncpy(&str6[i], "6", 1);
		strncpy(&str7[i], "7", 1);
		strncpy(&str8[i], "8", 1);
		i++;
	}
	free(str7);
	free(str8);
	str7 = (char*)malloc(sizeof(char) * 50);
	str8 = (char*)malloc(sizeof(char) * 140);
	str9 = (char*)malloc(sizeof(char) * 1025);
	i = 0;
	while (i < 200)
	{
		if (i < 140)
			strncpy(&str8[i], "8", 1);
		if (i < 50)
			strncpy(&str7[i], "7", 1);
		strncpy(&str9[i], "9", 1);
		i++;
	}
	str7 = (char*)realloc(str7, sizeof(char) * 198);
	i = 0;
	while (i < 198)
		strncpy(&str7[i++], "$", 1);
	ft_putstr("-------------Show_mem_ex--------------\n");
	show_alloc_mem_ex();
	ft_putstr("-------------Show_mem-----------------\n");
	show_alloc_mem();
	str9 = (char*)realloc(str9, 0);
	ft_putstr("-------------Show_mem_ex--------------\n");
	show_alloc_mem_ex();
	ft_putstr("-------------Show_mem-----------------\n");
	show_alloc_mem();
}



















