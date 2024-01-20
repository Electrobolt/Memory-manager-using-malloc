/***********************************************************/
/*                                                         */
/*                                                         */
/*    ft_putstrcol.c                                       */
/*                                                         */
/*    By: banthony <banthony@students.42.fr>               */
/*    Recoded by: Electrobolt <pharelledo06@gmail.com>     */
/*                                                         */
/*    Created: 2017/06/20 19:21:58 by banthony             */
/*    Updated: 2023/11/19 01:53:04 by Electrobolt          */
/*                                                         */
/***********************************************************/ 

#include "malloc.h"

void	ft_putstrcol(char *color, char *str)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(WHITE);
}
