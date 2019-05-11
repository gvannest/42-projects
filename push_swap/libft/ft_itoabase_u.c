/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:14:08 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/25 15:25:24 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_countdigits(uintmax_t value, char *base)
{
	int i;

	i = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		i++;
		value = value / ft_strlen(base);
	}
	return (i);
}

static void		ft_fillitoa(char *str, uintmax_t l, char *base)
{
	int i;

	i = 0;
	while (l > 0)
	{
		str[i] = base[l % ft_strlen(base)];
		l = l / ft_strlen(base);
		i++;
	}
}

char			*ft_itoabase_u(uintmax_t value, char *base)
{
	int			k;
	char		*str;

	k = ft_countdigits(value, base);
	if (!(str = ft_strnew(k)))
		return (0);
	str[k] = '\0';
	ft_fillitoa(str, value, base);
	return (ft_strrev(str));
}
