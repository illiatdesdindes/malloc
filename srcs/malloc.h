/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 15:01:39 by svachere          #+#    #+#             */
/*   Updated: 2014/04/19 20:08:09 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <unistd.h>
# include <sys/mman.h>
# define TINY_FACTOR 1
# define SMALL_FACTOR 16
# define TINY_ZONE (TINY_FACTOR * getpagesize())
# define SMALL_ZONE (SMALL_FACTOR * getpagesize())
# define TINY_DATA (TINY_FACTOR * getpagesize() / 100 - sizeof(t_block))
# define SMALL_DATA (SMALL_FACTOR * getpagesize() / 100 - sizeof(t_block))
# define ALIGN(x) (((((x) - 1) >> 3) << 3) + 8)

typedef struct	s_block
{
	size_t			size;
	struct s_block	*next;
	struct s_block	*prev;
	int				free;
}				t_block;

typedef struct	s_mem
{
	t_block		*tinies;
	t_block		*smalles;
	t_block		*larges;
}				t_mem;

t_mem	g_mem;

void	*malloc(size_t size);
void	*fmalloc(size_t size);
void	free(void *ptr);
void	ffree(void *ptr);
void	*realloc(void *ptr, size_t size);
t_block	*m_find_block(size_t size);
void	m_split_block(t_block *found, size_t size);

#endif
