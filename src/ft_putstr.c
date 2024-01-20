/***********************************************************/
/*                                                         */
/*                                                         */
/*    ft_putstr.c                                          */
/*                                                         */
/*    By: banthony <banthony@students.42.fr>               */
/*    Recoded by: Electrobolt <pharelledo06@gmail.com>     */
/*                                                         */
/*    Created: 2015/11/23 16:49:47 by banthony             */
/*    Updated: 2023/11/19 00:47:18 by Electrobolt          */
/*                                                         */
/***********************************************************/ 

#include <unistd.h> 
#include "malloc.h"

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}
