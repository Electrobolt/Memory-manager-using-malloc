/***********************************************************/
/*                                                         */
/*                                                         */
/*    test5.c                                              */
/*                                                         */
/*    By: banthony <banthony@students.42.fr>               */
/*    Recoded by: Electrobolt <pharelledo06@gmail.com>     */
/*                                                         */
/*    Created: 2017/10/03 15:19:01 by banthony             */
/*    Updated: ----/--/-- --:--:-- (not updated)           */
/*                                                         */
/***********************************************************/ 

#include "malloc.h"

static void	mft_putstr(char const *str)
{
	while (*str)
		write(1, str++, 1);
}

int		main(void)
{
	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	mft_putstr("\n---------show_alloc_mem()------------\n");
	show_alloc_mem();
	mft_putstr("\n---------show_alloc_mem_ex()---------\n");
//	show_alloc_mem_ex();
	return (0);
}
