/***********************************************************/
/*                                                         */
/*                                                         */
/*    ft_putchar_base.c                                    */
/*                                                         */
/*    By: banthony <banthony@students.42.fr>               */
/*    Recoded by: Electrobolt <pharelledo06@gmail.com>     */
/*                                                         */
/*    Created: 2017/08/15 14:39:40 by banthony             */
/*    Updated: 2023/11/17 20:17:01 by Electrobolt          */
/*                                                         */
/***********************************************************/ 

#include "malloc.h"

void	ft_putchar_base(unsigned char c, unsigned int base, char *tab)
{
	if (!tab || !base)
		return ;
	ft_putchar(tab[c / base]);
	ft_putchar(tab[c % base]);
}
