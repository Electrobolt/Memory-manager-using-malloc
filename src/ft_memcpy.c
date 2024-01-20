/***********************************************************/
/*                                                         */
/*                                                         */
/*    ft_memcpy.c                                          */
/*                                                         */
/*    By: banthony <banthony@students.42.fr>               */
/*    Recoded by: Electrobolt <pharelledo06@gmail.com>     */
/*                                                         */
/*    Created: 2015/12/02 19:31:06 by banthony             */
/*    Updated: 2023/11/14 23:37:41 by Electrobolt          */
/*                                                         */
/***********************************************************/ 

#include <string.h>
#include "malloc.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char * )dest;
	str2 = (unsigned char * )(unsigned long)src;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dest);
}
