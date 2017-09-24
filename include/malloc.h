/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:41:29 by banthony          #+#    #+#             */
/*   Updated: 2017/09/24 19:11:15 by banthony         ###   ########.fr       */
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
**	Permet d'aligner la taille, et de toujours
**	demander un multiple de 4 a mmap.
*/

#define align(x) (((((x)-1)>>2)<<2)+4)

/*
**	Tag pour les tailles des zones memoire, & etat de la freelist:
**	TINY	= [1 ; N]
**	SMALL	= [(N + 1) ; M]
**	LARGE	= [(M + 1) ; ...]
**	EMPTY	= Freelist totalement libre
**	PARTIAL	= Freelist compose de blocks libre et reserve
**	FULL	= Freelist totalement reserve
**	DATA	= Doit correspondre a tag[8], Fin de la metadata debut des Data users
*/

typedef enum		e_tag
{
	STATE, TYPE, TINY, SMALL, LARGE, EMPTY, PARTIAL, FULL, DATA,
}					t_tag;

/*
**	Stockage Metadata
*/

typedef struct		s_page
{
	size_t			size;
	struct s_page	*next;
	char			tag[8];
}					t_page;

void				my_free(void *ptr);
void				*my_malloc(size_t size);
void				*my_realloc(void *ptr, size_t size);
void				show_mem(void);

#endif











