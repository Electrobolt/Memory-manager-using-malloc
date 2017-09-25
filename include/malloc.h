/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:41:29 by banthony          #+#    #+#             */
/*   Updated: 2017/09/25 18:45:22 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MALLOC_H
# define	MALLOC_H

#include "libft.h"
#include <sys/mman.h>
#include <unistd.h>

#include <stdio.h>

/*
**	N = 1/16 choisi arbitrairement par rapport a M
**	M = 1/8 de getpagesize() (Doc sur Slab Allocation)
*/

#define TINY_LIMIT (size_t)getpagesize()/8
#define SMALL_LIMIT (size_t)getpagesize()/4

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
	struct s_page	*prev;
	char			tag[8];
}					t_page;

typedef struct		s_mdata
{
	size_t			size;
	struct s_mdata	*next;
	char			tag[8];
}					t_mdata;

# define MDATA_S sizeof(t_mdata)
# define PAGE_S sizeof(t_page)

extern void	*mem;
extern char endpage[6];
extern char enddata[6];

void				my_free(void *ptr);
void				*my_malloc(size_t size);
void				*my_realloc(void *ptr, size_t size);
void				show_alloc_mem(void);
void				show_alloc_mem_ex(void);

t_page				*new_page(t_page *page, size_t s);
t_mdata				*find_space(t_page *p, size_t s);
t_mdata				*get_free_mem(t_page *p, size_t s);
size_t				get_limit(size_t s);

#endif



















