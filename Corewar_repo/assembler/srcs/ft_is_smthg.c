/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_smthg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 10:40:03 by msicot            #+#    #+#             */
/*   Updated: 2018/08/02 10:41:45 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_is_sep(char c)
{
	if (c == SEPARATOR_CHAR || c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_is_nonsep(char c, int f)
{
	if (c == LABEL_CHAR || c == DIRECT_CHAR || c == '.' || c == '-'\
			|| (f == 1 && c == ' '))
		return (1);
	return (0);
}

int	ft_is_othchr(char c)
{
	if (c == LABEL_CHAR)
		return (1);
	if (c == DIRECT_CHAR)
		return (1);
	if (c == SEPARATOR_CHAR)
		return (1);
	if (c == '"')
		return (1);
	if (c == COMMENT_CHAR)
		return (1);
	return (0);
}

int	ft_is_comchar(int *num, char c)
{
	if (c == COMMENT_CHAR)
	{
		*num = 1;
		return (1);
	}
	return (0);
}
