/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:09:11 by banthony          #+#    #+#             */
/*   Updated: 2017/09/24 20:54:23 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*mem = NULL;
char	end[6] = "END-->";

void	show_mem(void)
{
	t_page *p;

	p = (t_page*)mem;
	while(p)
	{
		ft_putstrcol(BLUE, "Taille de la page:");
		ft_putstr(GREEN);
		ft_putnbrendl(p->size);
		ft_putstr(WHITE);
		ft_print_memory(p, p->size);
		p = p->next;
	}
}

t_page	*new_page(t_page *page, size_t s)
{
	t_page  *b;
	size_t n;

	b = NULL;
	(s < N) ? (n = N) : ((void)n);
	(s < M && s > N) ? (n = M) : ((void)n);
	(s > M) ? (n = s) : ((void)n);
	if (!(b = (t_page*)mmap(NULL, (sizeof(t_page) + n), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	ft_memset(b, 0, sizeof(b));
	b->size = n;
	b->tag[STATE] = EMPTY;
	ft_strncpy(&b->tag[2], end, 6);
	if (page)
	{
		while (page->next)
			page = page->next;
		page->next = b;
	}
	return (b);
}

t_page	*find_space(t_page *p, size_t s)
{
	if (p && s)
		;
	return (NULL);
}

void	*my_malloc(size_t size)
{
	t_page	*p;
	t_page	*tmp;

	if (!mem)	// Premier appel
	{
		if (!(p = new_page(NULL, align(size))))
			return (NULL);
		mem = p;
	}
	else
	{
		p = mem;
		if (!(tmp = find_space(p, align(size))))
			if (!(p = new_page(p, align(size))))
				return (NULL);
//			mem = p;	// mem toujours == au dernier maillon
	}
	return (&p->tag[DATA]);
}



