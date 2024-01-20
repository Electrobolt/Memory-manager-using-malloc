/***********************************************************/
/*                                                         */
/*                                                         */
/*    main1.c                                              */
/*                                                         */
/*    By: banthony <banthony@students.42.fr>               */
/*    Recoded by: Electrobolt <pharelledo06@gmail.com>     */
/*                                                         */
/*    Created: 2017/08/10 15:19:51 by banthony             */
/*    Updated: 2023/11/19 22:17:42 by Electrobolt          */
/*                                                         */
/***********************************************************/ 

#include "../malloc.h"
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char *str1, *str2, *str3, *str5;
	char *str4, *str6;
	char *str7, *str8, *str9;
	int i = 0;

	printf("page:%lu - mdata:%lu\n", sizeof(t_page), sizeof(t_mdata));
	str1 = (char* )malloc(sizeof(char) * 800);
	str2 = (char* )malloc(sizeof(char) * 40);
	str3 = (char* )malloc(sizeof(char) * 40);
	i = 0;
	while (i < 40)
	{
		ft_strncpy(&str1[i], "1", 1);
		ft_strncpy(&str2[i], "2", 1);
		ft_strncpy(&str3[i], "3", 1);
		i++;
	}
	//show_alloc_mem_ex();
	str4 = (char* )malloc(sizeof(char) * 2048);
	str5 = (char* )malloc(sizeof(char) * 40);
	str6 = (char* )malloc(sizeof(char) * 40);
	str7 = (char* )malloc(sizeof(char) * 40);
	str8 = (char* )malloc(sizeof(char) * 40);
	i = 0;
	while (i < 40)
	{
		ft_strncpy(&str4[i], "4", 1);
		ft_strncpy(&str5[i], "5", 1);
		ft_strncpy(&str6[i], "6", 1);
		ft_strncpy(&str7[i], "7", 1);
		ft_strncpy(&str8[i], "8", 1);
		i++;
	}
	//show_alloc_mem_ex();
//	free(str5);
	//show_alloc_mem_ex();
//	free(str6);
	//show_alloc_mem_ex();
	free(str7);
	//show_alloc_mem_ex();
	free(str8);
	//show_alloc_mem_ex();
	str7 = (char* )malloc(sizeof(char) * 50);
	//show_alloc_mem_ex();
	str8 = (char* )malloc(sizeof(char) * 140);
	//show_alloc_mem_ex();
//	free(str1);
	//show_alloc_mem_ex();
//	free(str2);
	//show_alloc_mem_ex();
//	free(str3);
	//show_alloc_mem_ex();
//	free(str4);
	//show_alloc_mem_ex();
	str9 = (char* )malloc(sizeof(char) * 200);
	i = 0;
	while (i < 200)
	{
		if (i < 140)
			ft_strncpy(&str8[i], "8", 1);
		if (i < 50)
			ft_strncpy(&str7[i], "7", 1);
		ft_strncpy(&str9[i], "9", 1);
		i++;
	}
//	free(str1);
//	free(str6);
//	free(str4);
//	free(str3);
//	free(str5);
//	free(str2);
//	free(str7);
//	free(str8);
//	free(str9);
/*	str1 = (char* )malloc(sizeof(char) * 4);
	i = 0;
	while (i < 8)
	ft_strncpy(&str1[i++], "1", 1);*/
//	show_alloc_mem_ex();
//	free(str8);
//	ft_putendlcol(CYAN, "FREE 8");
//	show_alloc_mem_ex();
	str7 = (char* )realloc(str7, sizeof(char) * 198);
	i = 0;
	while (i < 198)
		ft_strncpy(&str7[i++], "$", 1);
	show_alloc_mem_ex();
	show_alloc_mem();
}



















