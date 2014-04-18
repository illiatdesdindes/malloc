/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:25:06 by svachere          #+#    #+#             */
/*   Updated: 2013/11/26 16:41:22 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;
	char	*src;
	char	*dst;

	dst = (char*) s1;
	src = (char*) s2;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
