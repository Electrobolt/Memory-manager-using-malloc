/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:41:29 by banthony          #+#    #+#             */
/*   Updated: 2017/08/24 23:35:02 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MALLOC_H
# define	MALLOC_H

#include "libft.h"
#include <sys/mman.h>

/*
**	N = 1/16 choisi arbitrairement par rapport a M
**	M = 1/8 de getpagesize() (Doc sur Slab Allocation)
*/

#define N 296
#define M 512

/*
**	Tag pour les tailles des zones memoire, & etat de la freelist:
**	TINY	= [1 ; N]
**	SMALL	= [(N + 1) ; M]
**	LARGE	= [(M + 1) ; ...]
**	EMPTY	= Freelist totalement libre
**	PARTIAL	= Freelist compose de blocks libre et reserve
**	FULL	= Freelist totalement reserve
*/

typedef enum		e_tag
{
	VOID, TINY, SMALL, LARGE, EMPTY, PARTIAL, FULL,
}					t_tag;

/*
**	Stockage Metadata
*/

typedef struct		s_area
{
	void			*adr;
	size_t			size;
	struct s_list	*flst;
	struct s_area	*next;
	char			tag[8];
}					t_area;

void				my_free(void *ptr);
void				*my_malloc(size_t size);
void				*my_realloc(void *ptr, size_t size);

#endif
