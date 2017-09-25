/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:19:51 by banthony          #+#    #+#             */
/*   Updated: 2017/09/25 18:43:46 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *str, *str2, *str3, *str4;

/*	printf("Struct t_area size:%lu\n", s);
	printf("\tvoid\t*adr:%lu\n", sizeof(void*));
	printf("\tsize_t\tsize:%lu\n", sizeof(size_t));
	printf("\ts_list\t*flst:%lu\n", sizeof(t_list));
	printf("\ts_area\t*next:%lu\n", sizeof(struct s_area));
	printf("\tchar\ttag[8]:%lu\n", sizeof(char[8]));
*/	printf("page:%lu - mdata:%lu\n", sizeof(t_page), sizeof(t_mdata));
	str = (char*)my_malloc(sizeof(char) * 8);
	str2 = (char*)my_malloc(sizeof(char) * 24);
	str3 = (char*)my_malloc(sizeof(char) * 513);
	str4 = (char*)my_malloc(sizeof(char) * 513);
	ft_strncpy(str, "DataData", 8);
	ft_strncpy(str2, "Pokemon/Pokeball/Pikachu", 24);
	ft_strncpy(str3, "SALUT", 513);
	ft_strncpy(str4, "DataData", 513);
	// Affichage de la memoire
	show_alloc_mem_ex();
}



















