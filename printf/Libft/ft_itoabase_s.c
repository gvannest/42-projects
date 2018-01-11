/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:14:08 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/11 16:01:15 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countdigits(intmax_t value, int base)
{
	int i;

	i = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		i++;
		value = value / base;
	}
	return (i);
}

static void		ft_fillitoa(char *str, intmax_t l, char *tab, int base)
{
	int i;
	int k;

	i = 0;
	k = ft_countdigits(l, base);
	while (i < k)
	{
		(str)[i] = tab[(-l) % base];
		l = l / base;
		i++;
	}
}

char			*ft_itoabase_s(intmax_t value, int base)
{
	int			k;
	char		*str;
	intmax_t	l;
	uintmax_t	n;
	char		tab[16];

	ft_strncpy(tab, "0123456789ABCDEF", 17);
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
	if (value < 0 && base == 10)
		str[k] = '-';
	ft_fillitoa(str, l, tab, base);
	return (ft_strrev(str));
}
