/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:19:51 by banthony          #+#    #+#             */
/*   Updated: 2017/09/27 16:53:42 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *str, *str2, *str3, *str5;
	char *str4, *str6;
	char *str7, *str8, *str9;
	int i = 0;

/*	printf("Struct t_area size:%lu\n", s);
	printf("\tvoid\t*adr:%lu\n", sizeof(void*));
	printf("\tsize_t\tsize:%lu\n", sizeof(size_t));
	printf("\ts_list\t*flst:%lu\n", sizeof(t_list));
	printf("\ts_area\t*next:%lu\n", sizeof(struct s_area));
	printf("\tchar\ttag[8]:%lu\n", sizeof(char[8]));
*/	printf("page:%lu - mdata:%lu\n", sizeof(t_page), sizeof(t_mdata));
	str = (char*)my_malloc(sizeof(char) * 40);
	str2 = (char*)my_malloc(sizeof(char) * 40);
	str3 = (char*)my_malloc(sizeof(char) * 40);
	str4 = (char*)my_malloc(sizeof(char) * 40);
	str5 = (char*)my_malloc(sizeof(char) * 40);
	str6 = (char*)my_malloc(sizeof(char) * 40);
	str7 = (char*)my_malloc(sizeof(char) * 40);
	str8 = (char*)my_malloc(sizeof(char) * 200);
	str9 = (char*)my_malloc(sizeof(char) * 1024);
	while (i < 40)
	{
		ft_strncpy(&str[i], "X", 1);
		ft_strncpy(&str2[i], "X", 1);
		ft_strncpy(&str3[i], "X", 1);
		ft_strncpy(&str4[i], "X", 1);
		ft_strncpy(&str5[i], "X", 1);
		ft_strncpy(&str6[i], "X", 1);
		ft_strncpy(&str7[i], "X", 1);
		i++;
	}
	i = 0;
	while (i < 1024)
	{
		if (i < 200)
			ft_strncpy(&str8[i], "X", 1);
		ft_strncpy(&str9[i], "X", 1);
		i++;
	}

	my_free(str6);
	my_free(str4);
	my_free(str);
//	my_free(str3);
	my_free(str5);
	my_free(str2);
	my_free(str7);
//	my_free(str8);
//	my_free(str9);
	// Affichage de la memoire
	show_alloc_mem_ex();
}



















