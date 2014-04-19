/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 14:58:52 by svachere          #+#    #+#             */
/*   Updated: 2014/04/19 20:13:49 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void	free(void *ptr)
{
	t_block	*block;
	t_block	*prev;
	t_block	*next;

	block = (t_block*)(((char*)ptr) - sizeof(t_block));
	block->free = 1;
	prev = block->prev;
	next = block->next;
	if (next && next->free == 1)
	{
		block->next = next->next;
		next->prev = block;
		block->size = block->size + sizeof(t_block) + next->size;
	}
	if (prev && prev->free == 1)
	{
		prev->next = block->next;
		next->prev = prev;
		prev->size = prev->size + sizeof(t_block) + block->size;
	}
}
