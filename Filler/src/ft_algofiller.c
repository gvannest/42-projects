/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algofiller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:12:00 by gvannest          #+#    #+#             */
/*   Updated: 2018/03/07 15:32:24 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static void			ft_count_op(t_filler *game)
{
	int k;
	int i;

	k = 0;
	i = 0;
	while (i < BOARDC * BOARDL)
	{
		if (BOARD[i] == SHAPE_OP)
			k++;
		i++;
	}
	if (k == COUNT_OP)
		WIN_FILLER = 1;
	else
		COUNT_OP = k;
}

static void			ft_trick(t_filler *game)
{
	int j;

	j = 0;
	while (j < BOARDC * BOARDL)
	{
		(BOARD[j] != SHAPE_ME ? BOARD[j] = '.' : 0);
		j++;
	}
	BOARD[(BOARDC - 1)] = SHAPE_OP;
}

static void			ft_fill_maps(t_filler *game)
{
	int			i;
	int			j;
	static int	k = 0;

	i = 0;
	j = 0;
	if (BOARDC < 20 && SHAPE_ME == 'X' && k < SEUIL)
	{
		ft_trick(game);
		k++;
	}
	if (BOARDC < 90)
		ft_small_maps(game, k);
	else
	{
		ft_big_map(game, SHAPE_OP, MAP_OP);
		ft_big_map(game, SHAPE_ME, MAP_ME);
		while (i < BOARDC * BOARDL)
		{
			MAPOME[i] = MAP_OP[i] - MAP_ME[i];
			i++;
		}
	}
}

void				ft_algofiller(t_filler *game)
{
	int i;

	i = 0;
	ft_bzero(MAP_OP, sizeof(double) * BOARDC * BOARDL);
	ft_bzero(MAP_ME, sizeof(double) * BOARDC * BOARDL);
	ft_bzero(MAPOME, sizeof(double) * BOARDC * BOARDL);
	ft_bzero(MAP_SCORE, sizeof(double) * BOARDC * BOARDL);
	if (WIN_FILLER == 0)
	{
		ft_count_op(game);
		ft_fill_maps(game);
	}
	i = ft_influence(game);
	COOR_LN = i / BOARDC;
	COOR_CL = i % BOARDC;
}
