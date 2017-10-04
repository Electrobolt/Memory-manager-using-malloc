/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:41:29 by banthony          #+#    #+#             */
/*   Updated: 2017/10/04 19:49:08 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <unistd.h>

# define WHITE "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define CYAN "\033[36m"

/*
**	ALIGN - Arrondit SIZE a un multiple de 4
**	ALIGN_PSIZE - Arrondit SIZE a un multiple de getpagesize
*/

# define PS (size_t)getpagesize()
# define ALIGN(SIZE) (((((SIZE)-1)/4)*4)+4)
# define ALIGN_PSIZE(SIZE) (((((SIZE)-1)/PS)*PS)+PS)

/*
**	N - Calcul de la taille de la zone pour avoir au minimum 100 TINY
**		Le resultat est arrondit a un multiple de PS.
**	M - Idem mais cette fois avec SMALL_LIMIT.
**		Les zones peuvent potentiellement recevoir plus de 100 alloc,
**		du fait de l'arrondit de ALIGN_PSIZE.
**	DATA_MIN = Valeur min d'une allocation ou d'un mdata->size
**
**	END_PAGE & END_DATA sont des chaines de caracteres uniquement utile
**	au dev, lors d'un print_memory.
**	(Ces deux messages indiquent visuellement la Fin des metadata)
*/

# define MDATA_S sizeof(t_mdata)
# define PAGE_S sizeof(t_page)
# define TINY_LIMIT 1024
# define SMALL_LIMIT (TINY_LIMIT * 32)
# define N ALIGN_PSIZE(PAGE_S + ((MDATA_S + TINY_LIMIT) * 100))
# define M ALIGN_PSIZE(PAGE_S + ((MDATA_S + SMALL_LIMIT) * 100))
# define DATA_MIN 4
# define END_PAGE "PAGE->"
# define END_DATA "DATA->"

/*
**	Tag pour les tailles des zones memoire, & etat des mdata:
**	TINY	= [1 ; TINY_LIMIT]
**	SMALL	= [(TINY_LIMIT + 1) ; SMALL_LIMIT]
**	LARGE	= [(SMALL_LIMIT + 1) ; ...]
**	EMPTY	= Page libre (Aucune mdata presente, Permet de free la page)
**	PARTIAL	= Page avec des block de mdata en utilisation,
**			  mais il reste de la place pour dautre allocations.
**	FULL	= Page entierement remplit
**	DATA	= Doit correspondre a tag[8],
**			  Fin de la metadata debut des Data utilisateur en memoire
**	BLOCK	= Utiliser dans get_nb_block comme parametre pour state,
**			  Ce qui permet de compter tout les mdata quelquesoit leurs STATE.
**	SIZE	= Utiliser dans get_nb_block pour que la fonction
**			  return la taille total d'allocation user de la page.
*/

typedef enum		e_tag
{
	STATE, TYPE,
	TINY, SMALL, LARGE,
	EMPTY, PARTIAL, FULL,
	DATA,
	BLOCK, SIZE,
}					t_tag;

/*
**	Stockage Pages
*/
typedef struct		s_page
{
	size_t			size;
	struct s_page	*next;
	struct s_page	*prev;
	char			tag[8];
}					t_page;

/*
**	Stockage MetaData
*/
typedef struct		s_mdata
{
	size_t			size;
	struct s_mdata	*next;
	char			tag[8];
}					t_mdata;

/*
**	Variable globale debut de la liste de pages
*/
extern void	*g_mem;

/*
**	Lib Malloc (Fonctions Utilisateurs)
*/
void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem(void);
void				show_alloc_mem_ex(void);

/*
**	Lib Malloc (Fonctions Dev)
*/
t_page				*new_page(t_page *page, size_t s);
t_mdata				*find_space(t_page *p, size_t s);
t_mdata				*get_free_mem(t_page *p, size_t s);
t_mdata				*split_block(t_mdata *d, size_t s);
t_mdata				*find_ptr(void *ptr, t_page **p);
size_t				get_limit(size_t s);
char				get_malloc_tag_type(size_t s);
size_t				get_nb_block(t_page *p, char state);
void				show_malloc_type(char type);
void				defrag_mem(t_page *p);
size_t				get_size_area(size_t s);
void				show_dump_hex(void *ptr, size_t size);

/*
**	Fonctions de Libft
*/
void				ft_putchar(char const c);
size_t				ft_strlen(const char *s);
void				ft_putnbr(long long nb);
void				ft_putnbrendl(long long nb);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putstrcol(char *color, char *s);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_print_ptr(void *addr);
void				ft_putchar_base(unsigned char c, unsigned int base,
									char *tab);
void				ft_print_memory(void *addr, size_t size);
char				*ft_strncpy(char *dst, const char *src, size_t n);

#endif
