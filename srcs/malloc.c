/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 14:52:09 by svachere          #+#    #+#             */
/*   Updated: 2014/04/18 20:11:21 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

extern t_mem	g_mem;

void	m_init_tinies()
{
	char	*tinies;
	t_block	prev;
	t_block	curr = {g_mem.sizetiny, NULL, 1, {}};
	int		i;

	tinies = mmap(0, TINY_ZONE, PROT_READ | PROT_WRITE,
					MAP_ANON | MAP_PRIVATE, -1, 0);
	i = 0;
	while (i < 100)
	{
		*(tinies + (i * (g_mem.sizetiny + sizeof(t_block)))) =; 
	}
}

void	m_init_smalles();
{
	void	*smalles;

	smalles = mmap(0, SMALL_ZONE, PROT_READ | PROT_WRITE,
					MAP_ANON | MAP_PRIVATE, -1, 0);
}

void	m_init(size_t size)
{
	if (g_mem.sizetiny == 0)
	{
		g_mem.sizetiny = TINY_FACTOR * getpagesize() / 100 - sizeof(t_block);
		g_mem.sizesmall = SMALL_FACTORE * getpagesize() / 100 - sizeof(t_block);
	}
	if (size <= g_mem.sizetiny && g_mem.tinies == NULL)
		m_init_tinies();
	if (size <= g_mem.sizesmall && g_mem.smalles == NULL)
		m_init_smalles();
}

void	*malloc(size_t size)
{
	size = align4(size);
	m_init(size);
}
