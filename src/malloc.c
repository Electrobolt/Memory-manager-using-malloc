/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:09:11 by banthony          #+#    #+#             */
/*   Updated: 2017/08/21 15:09:36 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*my_malloc(size_t size)
{
	char *str;

	str = NULL;
	if (!size)
		return (NULL);
	str = (char*)mmap(NULL, size + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	ft_memset(str, '\0', size);
	return (str);
}
