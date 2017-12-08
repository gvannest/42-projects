/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:48:53 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/09 09:55:46 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*tab;
	int a;
	int i;

	if (min >= max)
		return (0);
	a = min;
	i = 0;
	if (!(tab = (int*)malloc(sizeof(*tab) * (max - min))))
		return (0);
	while (a < max)
	{
		tab[i] = a;
		a++;
		i++;
	}
	return (tab);
}
