/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:34:01 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/16 20:02:31 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_checklong(size_t n, int a)
{
	if ((a == 1 && n > 9223372036854775807UL) ||
		(a == -1 && n > 9223372036854775808UL))
		return (a == 1 ? -1 : 0);
	return (n * a);
}

int			ft_atoi(const char *str)
{
	size_t	n;
	int		a;
	size_t	i;

	n = 0;
	i = 0;
	a = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		a = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	return (ft_checklong(n, a));
}
