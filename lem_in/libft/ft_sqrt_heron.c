/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:29:35 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/27 10:29:07 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_sqrt_heron(double n, int precision)
{
	int		k;
	double	res;

	k = 0;
	res = n;
	if (n <= 0)
		return (0);
	while (k < precision)
	{
		res = (res + n / res) / 2;
		k++;
	}
	return (res);
}
