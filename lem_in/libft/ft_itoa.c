/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 08:57:54 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/23 11:46:04 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_itoa(int n, size_t k, char *str)
{
	long	l;
	size_t	i;

	l = n;
	if (n < 0)
	{
		l = -l;
		i = k;
		str[0] = '-';
	}
	else if (n == 0)
		str[0] = '0';
	else
		i = k - 1;
	while (l != 0)
	{
		str[i] = l % 10 + 48;
		l = l / 10;
		i--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	l;
	size_t	k;

	l = n;
	k = 0;
	str = 0;
	while (l != 0)
	{
		k++;
		l = l / 10;
	}
	if (n <= 0)
	{
		if (!(str = ft_strnew(k + 1)))
			return (0);
	}
	else if (!(str = ft_strnew(k)))
		return (0);
	str = ft_fill_itoa(n, k, str);
	return (str);
}
