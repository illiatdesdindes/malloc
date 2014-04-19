/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_split_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 16:23:49 by svachere          #+#    #+#             */
/*   Updated: 2014/04/19 20:00:21 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void	m_split_block(t_block *found, size_t size)
{
	t_block	*new;

	if (found->size - size >= sizeof(t_block) + 8)
	{
		new = (t_block*)(((char*)found) + size + sizeof(t_block));
		new->size = found->size - size - sizeof(t_block);
		new->next = found->next;
		new->prev = found;
		new->free = 1;
		if (new->next)
			new->next->prev = new;
		found->next = new;
		found->size = size;
	}
}
