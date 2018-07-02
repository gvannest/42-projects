/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_influence_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 09:35:28 by gvannest          #+#    #+#             */
/*   Updated: 2018/03/06 17:06:20 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static void			ft_min_influence(t_filler *game, int i)
{
	int		k;
	double	som_inf;
	int		pos;

	k = 0;
	som_inf = 0;
	while (k < PIECE_NBLN * PIECE_NBCOL)
	{
		pos = i + k % PIECE_NBCOL + k / PIECE_NBCOL * BOARDC;
		if (PIECE[k] != '.')
			som_inf = som_inf + MAPOME[pos];
		k++;
	}
	MAP_SCORE[i] = som_inf;
}

int					ft_influence(t_filler *game)
{
	int		i;
	double	min;
	int		i_min;

	i = 1;
	min = 0;
	i_min = 0;
	while (i < BOARDC * BOARDL)
	{
		if (ft_validspot(game, i))
		{
			if (WIN_FILLER == 1)
				return (i);
			ft_min_influence(game, i);
			if (min == 0 || (MAP_SCORE[i] < min))
			{
				min = MAP_SCORE[i];
				i_min = i;
			}
		}
		i++;
	}
	return (i_min);
}
