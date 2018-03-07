/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:13:59 by gvannest          #+#    #+#             */
/*   Updated: 2018/03/07 11:43:18 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	double		ft_distance_small(t_filler *game, int i, char c)
{
	int		k;
	double	d;
	double	tab[3];

	k = 0;
	d = 0;
	while (k < BOARDC * BOARDL)
	{
		if (BOARD[k] == c && BOARD[i] != c)
		{
			tab[1] = (k / BOARDC - i / BOARDC);
			tab[0] = (k % BOARDC - i % BOARDC);
			tab[2] = ft_sqrt_heron(tab[0] * tab[0] + tab[1] * tab[1], 10);
			(d == 0 || tab[2] < d ? d = tab[2] : 0);
		}
		k++;
	}
	return (d);
}

void				ft_small_maps(t_filler *game, int k)
{
	int		i;

	i = 0;
	while (i < BOARDC * BOARDL)
	{
		MAP_OP[i] = ft_distance_small(game, i, SHAPE_OP);
		if (BOARDC > 20 || k >= SEUIL || SHAPE_ME == 'O')
			MAPOME[i] = MAP_OP[i] - ft_distance_small(game, i, SHAPE_ME);
		else
			MAPOME[i] = MAP_OP[i];
		i++;
	}
}
