/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 15:01:39 by svachere          #+#    #+#             */
/*   Updated: 2014/04/18 19:18:15 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <unistd.h>
# define TINY_FACTOR 8
# define SMALL_FACTOR 16
# define ALIGN(x) (((((x) - 1) >> 3) << 3) + 8)

typedef struct	s_block
{
	struct s_block	*next;
	size_t			size;
	int				free;
	char			data[1];
}				t_block;

typedef struct	s_mem
{
	t_block		*tinies;
	t_block		*smalles;
	t_block		*larges;
	size_t		sizetiny;
	size_t		sizesmall;
}				t_mem;

t_mem	g_mem = {NULL, NULL, NULL, 0, 0};

void	*malloc(size_t size);
void	free(void *ptr);
void	*realloc(void *ptr, size_t size);

#endif
