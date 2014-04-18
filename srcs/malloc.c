/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 14:52:09 by svachere          #+#    #+#             */
/*   Updated: 2014/04/18 18:53:34 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

extern t_mem	g_mem;

void	m_init_tinies();

void	m_init_smalles();

void	m_init(size_t size)
{
	if (g_mem.sizetiny == 0)
	{
		g_mem.sizetiny = ;
		g_mem.sizesmall = getpagesize() * 2;
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
