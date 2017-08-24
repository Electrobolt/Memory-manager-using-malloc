/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:19:51 by banthony          #+#    #+#             */
/*   Updated: 2017/08/25 00:08:25 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	void *str;
	size_t s = sizeof(t_area);

	printf("Struct t_area size:%lu\n", s);
	printf("\tvoid\t*adr:%lu\n", sizeof(void*));
	printf("\tsize_t\tsize:%lu\n", sizeof(size_t));
	printf("\ts_list\t*flst:%lu\n", sizeof(t_list));
	printf("\ts_area\t*next:%lu\n", sizeof(struct s_area));
	printf("\tchar\ttag[8]:%lu\n", sizeof(char[8]));
//	Demande d'une zone de 8
	str = my_malloc(sizeof(char) * 8);
//	Remplissage de la zone fournie
	ft_strncpy(str, "DataData", 8);
//	Affichage zone avec header
	ft_print_memory(str - s, 64);
}



















