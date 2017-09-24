/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:19:51 by banthony          #+#    #+#             */
/*   Updated: 2017/09/24 19:19:26 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

extern t_page *mem;

int main(void)
{
	char *str, *str2, *str3;

/*	printf("Struct t_area size:%lu\n", s);
	printf("\tvoid\t*adr:%lu\n", sizeof(void*));
	printf("\tsize_t\tsize:%lu\n", sizeof(size_t));
	printf("\ts_list\t*flst:%lu\n", sizeof(t_list));
	printf("\ts_area\t*next:%lu\n", sizeof(struct s_area));
	printf("\tchar\ttag[8]:%lu\n", sizeof(char[8]));
*/
	str = (char*)my_malloc(sizeof(char) * 8);
	str2 = (char*)my_malloc(sizeof(char) * 16);
	str3 = (char*)my_malloc(sizeof(char) * 300);
	ft_strncpy(str, "DataData", 8);
	ft_strncpy(str2, "Pokemon/Pokeball", 16);
	ft_strncpy(str3, "SALUT", 16);
	// Affichage de la memoire
	show_mem();
}



















