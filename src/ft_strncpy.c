/***********************************************************/
/*                                                         */
/*                                                         */
/*    ft_strncpy.c                                         */
/*                                                         */
/*    By: banthony <banthony@students.42.fr>               */
/*    Recoded by: Electrobolt <pharelledo06@gmail.com>     */
/*                                                         */
/*    Created: 2015/11/24 12:39:35 by banthony             */
/*    Updated: 2023/11/17 18:03:54 by Electrobolt          */
/*                                                         */
/***********************************************************/ 

#include <string.h>
#include "malloc.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dst[index] = '\0';
		index++;
	}
	return (dst);
}
