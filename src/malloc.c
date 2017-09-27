/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:09:11 by banthony          #+#    #+#             */
/*   Updated: 2017/09/27 20:45:51 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void *g_mem = NULL;
char g_endpage[6] = "PAGE->";
char g_enddata[6] = "DATA->";

t_page	*new_page(t_page *page, size_t s)
{
	t_page	*b;
	t_mdata	*p;
	size_t	n;

	n = get_limit(s);
	if (!(b = mmap(NULL, (PAGE_S + n),
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	ft_memset(b, 0, PAGE_S + n);
	b->size = n;
	b->tag[STATE] = PARTIAL;
	if (b->size == s)
		b->tag[STATE] = FULL;
	ft_strncpy(&b->tag[2], g_endpage, 6);// provisoire
	p = (void*)&b->tag[DATA];
	p->size = s;
	p->tag[STATE] = FULL;
	ft_strncpy(&p->tag[2], g_enddata, 6);//provisoire
	if (page)
	{
		while (page->next)
			page = page->next;
		page->next = b;
		b->prev = page;
	}
	return (b);
}

/*
  	Parcourir mdata
	{
		Si mdata empty
			if (mdata->s < s + MDATA_S) //Block trop petit
				continue ;
			if (mdata->s >= s + MDATA_S) //Block assez grand ou egal au besoin
			{
				if (mdata->s > (s + (MDATA_S + DATA_MIN))) // (s + 24 + 4) = (s + 28)
					split_block(mdata, s);
					split mdata->tag[DATA] + s;
					creer un new bloc avec le restant; //(new->s sera egale a DATA_MIN au minimum)
					return le bloc pour l'utilisateur (s)
				else
					(mdata->s est inf a s + 28)
					Utilisation du block existant sans faire de split;
			}
	}
*/

t_mdata	*split_block(t_mdata *d, size_t s)
{
	t_mdata *new;

	// New positioner en memoire juste derriere d
	new = (void*)((char*)&d->tag[DATA] + s);
	// Insertion de new dans la liste
	new->next = d->next;
	d->next = new;
	new->size = (d->size - (MDATA_S +  s));
	d->size = s;
	return (new);
}

t_mdata	*find_space(t_page *p, size_t s)
{
	t_mdata *tmp;
	t_mdata	*last;
	size_t	reserved;

	reserved = 0;
	if (!p)
		return (NULL);
	last = NULL;
	tmp = (void*)&p->tag[DATA];
	while (tmp->next)
	{
		reserved += (tmp->size + MDATA_S);
		tmp = tmp->next;
	}
	reserved += (tmp->size + MDATA_S);
	if (p->size >= (reserved + MDATA_S + s))
	{
		last = (void*)((char*)&tmp->tag[DATA] + tmp->size);
		last->size = s;
//		last->next = NULL;	// Necessaire ?
		last->tag[STATE] = FULL;
		if (p->size == (reserved + MDATA_S + s))
			p->tag[STATE] = FULL;
		tmp->next = last;
		ft_strncpy(&last->tag[2], g_enddata, 6);//provisoire
	}
	return (last);
}

t_mdata	*get_free_mem(t_page *p, size_t s)
{
	t_mdata	*last;
	t_page	*page;
	size_t	lim;

	if (!p)
		return (NULL);
	last = NULL;
	lim = get_limit(s);
	page = p;
	while (page)
	{
		if (page->size == lim && page->tag[STATE] <= PARTIAL)
			if ((last = find_space(page, s)))
				break ;
		page = page->next;
	}
	return (last);
}

void	*my_malloc(size_t size)
{
	t_page	*p;
	t_mdata	*tmp;

	if (size <= 0)
		return (NULL);
	if (!g_mem)
	{
		if (!(p = new_page(NULL, ALIGN(size))))
			return (NULL);
		g_mem = p;
	}
	else
	{
		p = g_mem;
		if (!(tmp = get_free_mem(p, ALIGN(size))))
		{
			if (!(p = new_page(p, ALIGN(size))))
				return (NULL);
		}
		else
			return ((void*)&tmp->tag[DATA]);
	}
	return ((void*)((char*)&p->tag[DATA] + MDATA_S));
}
