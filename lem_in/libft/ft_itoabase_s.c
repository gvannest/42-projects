/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:14:08 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/16 12:06:13 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countdigits(intmax_t value, char *base)
{
	int i;

	i = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		i++;
		value = value / ft_strlen(base);
	}
	return (i);
}

static void		ft_fillitoa(char *str, intmax_t l, char *base)
{
	int i;
	int k;

	i = 0;
	k = ft_countdigits(l, base);
	while (i < k)
	{
		(str)[i] = base[(l) % ft_strlen(base)];
		l = l / ft_strlen(base);
		i++;
	}
}

char			*ft_itoabase_s(intmax_t value, char *base)
{
	int			k;
	char		*str;
	intmax_t	l;
	uintmax_t	n;

	if (value == LLONG_MIN)
	{
		n = LLONG_MAX;
		str = ft_itoabase_u(++n, base);
		return (str);
	}
	l = value;
	if (l < 0)
		l = -l;
	k = ft_countdigits(l, base);
	if (!(str = ft_strnew(k + 1)))
		return (0);
	if (value < 0 && ft_strlen(base) == 10)
		str[k] = '-';
	ft_fillitoa(str, l, base);
	return (ft_strrev(str));
}
