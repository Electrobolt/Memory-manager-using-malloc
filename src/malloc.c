/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:09:11 by banthony          #+#    #+#             */
/*   Updated: 2017/08/24 23:54:32 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*my_malloc(size_t size)
{
	void *ptr;
	t_area *test;
	char end[8] = "THE END-";

	ptr = NULL;
	if (!size)
		return (NULL);
	if (!(ptr = mmap(NULL, size + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	ft_memset(ptr, '\0', size + 1);
	if (!(test = (t_area*)mmap(NULL, sizeof(t_area), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	ft_memset(test, '\0', sizeof(t_area));
	test->size = 42;
	ft_strncpy(test->tag, end, 8);
	test->adr = ptr;
	return (test->adr);
}
















