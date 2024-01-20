/***********************************************************/
/*                                                         */
/*                                                         */
/*    ft_strlen.c                                          */
/*                                                         */
/*    By: banthony <banthony@students.42.fr>               */
/*    Recoded by: Electrobolt <pharelledo06@gmail.com>     */
/*                                                         */
/*    Created: 2015/11/24 15:24:58 by banthony             */
/*    Updated: 2023/11/17 19:27:14 by Electrobolt          */
/*                                                         */
/***********************************************************/ 

#include <string.h>
#include "malloc.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}
