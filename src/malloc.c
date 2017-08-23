/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:09:11 by banthony          #+#    #+#             */
/*   Updated: 2017/08/23 19:24:50 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*my_malloc(size_t size)
{
	void *ptr;

	ptr = NULL;
	if (!size)
		return (NULL);
	if (!(ptr = mmap(NULL, size + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	ft_memset(ptr, '\0', size);
	return (ptr);
}










