/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:09:11 by banthony          #+#    #+#             */
/*   Updated: 2017/08/25 00:18:16 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*my_malloc(size_t size)
{
	void *ptr;
	t_area *tmp;
	char end[8] = "THEEND->";

	ptr = NULL;
	if (!size)
		return (NULL);
	if (!(ptr = mmap(NULL, size + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	if (!(tmp = (t_area*)mmap(NULL, sizeof(t_area), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	ft_memset(ptr, '\0', size + 1);
	tmp->size = 42;
	ft_strncpy(tmp->tag, end, 8);
	ptr = (void*)tmp;
	return (&ptr[40]);
}


















