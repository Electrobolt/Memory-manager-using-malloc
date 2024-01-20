/***********************************************************/
/*                                                         */
/*                                                         */
/*    ft_putnbr.c                                          */
/*                                                         */
/*    By: banthony <banthony@students.42.fr>               */
/*    Recoded by: Electrobolt <pharelledo06@gmail.com>     */
/*                                                         */
/*    Created: 2015/11/24 17:22:04 by banthony             */
/*    Updated: 2023/11/18 21:52:10 by Electrobolt          */
/*                                                         */
/***********************************************************/ 

#include "malloc.h"

void	ft_putnbr(long long nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar((char)(nb + '0'));
}
