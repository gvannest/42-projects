/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:14:08 by gvannest          #+#    #+#             */
/*   Updated: 2017/12/19 15:08:47 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countdigits(uintmax_t value, int base)
{
	int i;

	i = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		i++;
		value = value / base;
	}
	return (i);
}

static void		ft_fillitoa(char *str, uintmax_t l, char *tab, int base)
{
	int i;
	int k;

	i = 0;
	k = ft_countdigits(l, base);
	while (i < k)
	{
		(str)[i] = tab[l % base];
		l = l / base;
		i++;
	}
}

char			*ft_itoabase_u(uintmax_t value, int base)
{
	int			k;
	char		*str;
	char		tab[16];

	ft_strncpy(tab, "0123456789ABCDEF", 17);
	k = ft_countdigits(value, base);
	if (!(str = ft_strnew(k)))
		return (0);
	str[k] = '\0';
	ft_fillitoa(str, value, tab, base);
	return (ft_strrev(str));
}
