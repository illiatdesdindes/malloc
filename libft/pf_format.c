/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 16:23:28 by svachere          #+#    #+#             */
/*   Updated: 2014/03/11 18:05:43 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			extract_flag(char *s, t_format *format)
{
	if (*s == '#' || *s == '0' || *s == '-' || *s == '+')
	{
		format->flag = *s;
		return (1);
	}
	format->flag = 0;
	return (0);
}

int			extract_width(char **s, t_format *format)
{
	format->width = 0;
	while (ft_isdigit(**s))
	{
		format->width = format->width * 10 + **s - '0';
		*s += 1;
	}
	return (1);
}

int			extract_type(char *s, t_format *format)
{
	int		i;
	char	types[] = {'%', 'd', 's', 'c', 'p', 0};

	i = -1;
	while (types[++i])
	{
		if (types[i] == *s)
		{
			format->type = i;
			return (1);
		}
	}
	format->type = -1;
	return (0);
}

t_format	pf_extract_format(char **s)
{
	t_format	format;

	if (extract_flag(*s, &format))
		*s += 1;
	extract_width(s, &format);
	if (extract_type(*s, &format))
		*s += 1;
	return (format);
}
