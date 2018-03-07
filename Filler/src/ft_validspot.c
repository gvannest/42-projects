/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validspot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:35:42 by gvannest          #+#    #+#             */
/*   Updated: 2018/03/06 18:29:01 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		ft_validspot(t_filler *game, int i)
{
	int k;
	int pos;
	int c_valid;
	int c_invalid;

	k = 0;
	c_valid = 0;
	c_invalid = 0;
	if (i / BOARDC <= BOARDL - PIECE_NBLN &&
		i % BOARDC <= BOARDC - PIECE_NBCOL)
	{
		while (k < PIECE_NBLN * PIECE_NBCOL)
		{
			pos = i + k % PIECE_NBCOL + k / PIECE_NBCOL * BOARDC;
			if (BOARD[pos] == SHAPE_ME && PIECE[k] == SHAPE_ME)
				c_valid++;
			(BOARD[pos] == SHAPE_OP && PIECE[k] == SHAPE_ME ? c_invalid++ : 1);
			k++;
		}
		if (c_valid == 1 && c_invalid == 0)
			return (1);
	}
	return (0);
}
