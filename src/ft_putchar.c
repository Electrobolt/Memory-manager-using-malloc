/***********************************************************/
/*                                                         */
/*                                                         */
/*    ft_putchar.c                                         */
/*                                                         */
/*    By: banthony <banthony@students.42.fr>               */
/*    Recoded by: Electrobolt <pharelledo06@gmail.com>     */
/*                                                         */
/*    Created: 2015/11/23 15:28:48 by banthony             */
/*    Updated: 2023/11/17 20:25:33 by Electrobolt          */
/*                                                         */
/***********************************************************/ 

#include <unistd.h>
#include "malloc.h"

void	ft_putchar(char const c)
{
	write(1, &c, 1);
}
