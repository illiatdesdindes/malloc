/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 14:52:09 by svachere          #+#    #+#             */
/*   Updated: 2014/04/19 20:13:49 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>


t_block	*m_init_zone(size_t zone_size)
{
	t_block	*head;

	head = mmap(0, zone_size, PROT_READ | PROT_WRITE,
					MAP_ANON | MAP_PRIVATE, -1, 0);
	head->size = zone_size - sizeof(t_block);
	head->next = NULL;
	head->prev = NULL;
	head->free = 1;
	return (head);
}

void	m_init(size_t size)
{
	static int	init = 0;
	if (init == 0)
	{
		g_mem.tinies = NULL;
		g_mem.smalles = NULL;
		g_mem.larges = NULL;
		init = 1;
	}
	if (g_mem.tinies == NULL && size <= TINY_DATA)
		g_mem.tinies = m_init_zone(TINY_ZONE);
	else if (g_mem.smalles == NULL && size <= SMALL_DATA)
		g_mem.smalles = m_init_zone(SMALL_ZONE);
}

void	*malloc(size_t size)
{
	t_block	*found;

	size = ALIGN(size);
	m_init(size);
	found = m_find_block(size);
	if (found == NULL)
		return (NULL);
	found->free = 0;
	m_split_block(found, size);
	return ((void*)(((char*)found) + sizeof(t_block)));
}
