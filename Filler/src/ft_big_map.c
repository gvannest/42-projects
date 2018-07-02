/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:04:38 by gvannest          #+#    #+#             */
/*   Updated: 2018/03/06 17:01:37 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	void	ft_fill_big(t_filler *game, int m, int d, double *map)
{
	int i;
	int cl;

	i = 0;
	while (i < BOARDC * BOARDL)
	{
		if (map[i] == 0)
		{
			cl = i % BOARDC;
			if (i - BOARDC >= 0 && map[i - BOARDC] == m)
				map[i] = d;
			if (i + BOARDC < BOARDL * BOARDC && map[i + BOARDC] == m)
				map[i] = d;
			if (cl - 1 >= 0 && map[i - 1] == m)
				map[i] = d;
			if (cl + 1 < BOARDC && map[i + 1] == m)
				map[i] = d;
		}
		i++;
	}
}

static int		ft_check(t_filler *game, double *map)
{
	int i;

	i = 0;
	while (i < BOARDC * BOARDL)
	{
		if (map[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

void			ft_big_map(t_filler *game, char c, double *map)
{
	int i;
	int m;
	int d;

	i = 0;
	m = -1;
	d = 1;
	while (i < BOARDC * BOARDL)
	{
		if (BOARD[i] == c)
			map[i] = -1;
		i++;
	}
	while (ft_check(game, map) == 0)
	{
		ft_fill_big(game, m, d, map);
		(m == -1 ? m = 1 : m++);
		d++;
	}
}
