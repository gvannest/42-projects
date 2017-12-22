/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:14:08 by gvannest          #+#    #+#             */
/*   Updated: 2017/12/19 15:52:52 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countdigits(intmax_t value, int base)
{
	int i;

	i = 0;
	if (value == 0)
		return (1);
	while (value < 0)
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
	char		tab[16];

	l = value;
	ft_strncpy(tab, "0123456789ABCDEF", 17);
	if (l > 0)
		l = -l;
	k = ft_countdigits(l, base);
	if (value < 0 && base == 10)
	{
		if (!(str = ft_strnew(k + 1)))
			return (0);
		str[k + 1] = '\0';
		str[k] = '-';
	}
	else
	{
		if (!(str = ft_strnew(k)))
			return (0);
		str[k] = '\0';
	}
	ft_fillitoa(str, l, tab, base);
	return (ft_strrev(str));
}
