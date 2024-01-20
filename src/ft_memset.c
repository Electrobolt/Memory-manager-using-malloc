/***********************************************************/
/*                                                         */
/*                                                         */
/*    ft_memset.c                                          */
/*                                                         */
/*    By: banthony <banthony@students.42.fr>               */
/*    Recoded by: Electrobolt <pharelledo06@gmail.com>     */
/*                                                         */
/*    Created: 2015/11/26 18:08:13 by banthony             */
/*    Updated: 2023/11/15 00:16:24 by Electrobolt          */
/*                                                         */
/***********************************************************/ 

#include <string.h>
#include "malloc.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char * )b;
	i = 0;
	while (i < len)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
