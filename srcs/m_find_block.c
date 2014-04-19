/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_find.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 16:07:27 by svachere          #+#    #+#             */
/*   Updated: 2014/04/19 20:13:43 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

# include <libft.h>

t_block	*m_find_block_zone(size_t size, t_block *zone)
{
	t_block	*found;

	found = zone;
	while (found)
	{
		if (found->free && size <= found->size)
			return (found);
		found = found->next;
	}
	return (NULL);
}

t_block	*m_find_block(size_t size)
{
	t_block	*found;

	found = NULL;
	if (size <= TINY_DATA)
		found = m_find_block_zone(size, g_mem.tinies);
	else if (size <= SMALL_DATA)
		found = m_find_block_zone(size, g_mem.smalles);
	return (found);
}
