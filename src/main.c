/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:19:51 by banthony          #+#    #+#             */
/*   Updated: 2017/09/27 20:15:06 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *str1, *str2, *str3, *str5;
	char *str4, *str6;
	char *str7, *str8, *str9;
	int i = 0;

	printf("page:%lu - mdata:%lu\n", sizeof(t_page), sizeof(t_mdata));
	str1 = (char*)my_malloc(sizeof(char) * 40);
	str2 = (char*)my_malloc(sizeof(char) * 40);
	str3 = (char*)my_malloc(sizeof(char) * 40);
	i = 0;
	while (i < 40)
	{
		ft_strncpy(&str1[i], "1", 1);
		ft_strncpy(&str2[i], "2", 1);
		ft_strncpy(&str3[i], "3", 1);
		i++;
	}
	my_free(str2);
	str4 = (char*)my_malloc(sizeof(char) * 40);
	str5 = (char*)my_malloc(sizeof(char) * 40);
	str6 = (char*)my_malloc(sizeof(char) * 40);
	str7 = (char*)my_malloc(sizeof(char) * 40);
	str8 = (char*)my_malloc(sizeof(char) * 200);
	str9 = (char*)my_malloc(sizeof(char) * 600);
	i = 0;
	while (i < 40)
	{
		ft_strncpy(&str4[i], "4", 1);
		ft_strncpy(&str5[i], "5", 1);
		ft_strncpy(&str6[i], "6", 1);
		ft_strncpy(&str7[i], "7", 1);
		i++;
	}
	i = 0;
	while (i < 600)
	{
		if (i < 200)
			ft_strncpy(&str8[i], "8", 1);
		ft_strncpy(&str9[i], "9", 1);
		i++;
	}
//	my_free(str1);
//	my_free(str6);
//	my_free(str4);
//	my_free(str3);
//	my_free(str5);
//	my_free(str2);
	my_free(str7);
//	my_free(str8);
	my_free(str9);
	show_alloc_mem_ex();
}



















