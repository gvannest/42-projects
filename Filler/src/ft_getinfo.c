/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:15:54 by gvannest          #+#    #+#             */
/*   Updated: 2018/03/07 16:51:54 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static int			ft_getboard(t_filler *game, char **line)
{
	char			*ptr;
	int				k;

	ptr = 0;
	k = 0;
	if (BOARDL == 0 && ft_strstr(*line, "Plateau"))
	{
		ptr = ft_strchr(*line, ' ');
		BOARDL = ft_atoi(ptr);
		ptr = ft_strchr(ptr + 1, ' ');
		BOARDC = ft_atoi(ptr);
		if (!(BOARD = ft_strnew(BOARDL * BOARDC)))
			return (-1);
		if (!(MAP_OP = (double*)malloc(sizeof(double) * (BOARDL * BOARDC))))
			return (-1);
		if (!(MAP_ME = (double*)malloc(sizeof(double) * (BOARDL * BOARDC))))
			return (-1);
		if (!(MAPOME = (double*)malloc(sizeof(double) * (BOARDL * BOARDC))))
			return (-1);
		if (!(MAP_SCORE = (double*)malloc(sizeof(double) * (BOARDL * BOARDC))))
			return (-1);
	}
	if (ft_isdigit(*line[0]))
		ft_strcat(BOARD, *line + 4);
	return (0);
}

static int			ft_getpiece(t_filler *game, char **line)
{
	char		*ptr;
	int			k;

	ptr = 0;
	k = 0;
	if (ft_strstr(*line, "Piece"))
	{
		ptr = ft_strchr(*line, ' ');
		PIECE_NBLN = ft_atoi(ptr);
		ptr = ft_strchr(ptr + 1, ' ');
		PIECE_NBCOL = ft_atoi(ptr);
		if (!(PIECE = ft_strnew(PIECE_NBLN * PIECE_NBCOL)))
			return (-1);
	}
	if (*line[0] == '.' || *line[0] == '*')
	{
		ft_strcat(PIECE, *line);
		while (PIECE[k])
			(PIECE[k] == '*' ? PIECE[k++] = SHAPE_ME : k++);
		PIECE_LNCOUNT++;
	}
	return (0);
}

static void			ft_getforme(t_filler *game, char **line)
{
	SHAPE_ME = 'X';
	if (ft_strstr(*line, "gvannest") && ft_strchr(*line, '1'))
	{
		SHAPE_ME = 'O';
		SHAPE_OP = 'X';
	}
	else
		SHAPE_OP = 'O';
}

int					ft_getinfo(t_filler *game, char **line)
{
	if (SHAPE_ME == 0 && ft_strstr(*line, "$$$"))
		ft_getforme(game, line);
	if (ft_getboard(game, line) < 0)
		return (-1);
	if (ft_getpiece(game, line) < 0)
		return (-1);
	if (PIECE_LNCOUNT == PIECE_NBLN && PIECE_NBLN != 0)
	{
		ft_strdel(line);
		return (1);
	}
	return (0);
}
