/***********************************************************/
/*                                                         */
/*                                                         */
/*    ft_putendl.c                                         */
/*                                                         */
/*    By: banthony <banthony@students.42.fr>               */
/*    Recoded by: Electrobolt <pharelledo06@gmail.com>     */
/*                                                         */
/*    Created: 2015/11/26 16:11:27 by banthony             */
/*    Updated: 2023/11/17 20:46:29 by Electrobolt          */
/*                                                         */
/***********************************************************/ 

#include "malloc.h"

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
