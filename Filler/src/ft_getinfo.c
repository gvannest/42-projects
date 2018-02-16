/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:15:54 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/16 17:06:19 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static int		ft_getboard_updated(t_filler *game, char **line)
{
	char	*ptr;
	size_t	i;

	ptr = 0;
	i = 0;
	while (!ft_isdigit(*line[0]))
		get_next_line(0, line);
	while (BOARD[i])
	{
		if (ft_strcmp(BOARD[i], *line + 4) != 0)
			BOARD[i] = *line + 4;
		i++;
		get_next_line(0, line);
	}
	return (0);
}

static int		ft_getboard_init(t_filler *game, char **line)
{
	char	*ptr;
	size_t	i;

	ptr = 0;
	i = 0;
	while (!ft_strstr(*line, "Plateau"))
		get_next_line(0, line);
	ptr = ft_strchr(*line, ' ');
	BOARD_NBLN = ft_atoi(ptr);
	ptr = ft_strchr(ptr + 1, ' ');
	BOARD_NBCOL = ft_atoi(ptr);
	while (!ft_isdigit(*line[0]))
		get_next_line(0, line);
	if (!(BOARD = (char**)malloc(sizeof(char*) * (BOARD_NBLN + 1))))
		return (-1);
	BOARD[BOARD_NBLN] = 0;
	get_next_line(0, line);
	while (!ft_strstr(*line, "Piece"))
	{
		BOARD[i++] = ft_strdup(*line + 4);
		get_next_line(0, line);
	}
	return (0);
}

static int		ft_getpiece(t_filler *game, char **line)
{
	char	*ptr;
	int		i;

	ptr = 0;
	i = 0;
	while (!ft_strstr(*line, "Piece"))
		get_next_line(0, line);
	ptr = ft_strchr(*line, ' ');
	PIECE_NBLN = ft_atoi(ptr);
	ptr = ft_strchr(ptr + 1, ' ');
	PIECE_NBCOL = ft_atoi(ptr);
	if (!(PIECE = (char**)malloc(sizeof(char*) * (PIECE_NBLN + 1))))
		return (-1);
	PIECE[PIECE_NBLN] = 0;
	while (i < PIECE_NBLN)
	{
		get_next_line(0, line);
		PIECE[i++] = ft_strdup(*line);
	}
	return (0);
}

static void		ft_getforme(t_filler *game, char **line)
{
	FORME = 'X';
	while (!ft_strstr(*line, "$$$"))
		get_next_line(0, line);
	if (ft_strstr(*line, "gvannest"))
		(ft_strchr(*line, '1') ? FORME = 'O' : FORME);
}

void			ft_getinfo(t_filler *game, char **line)
{
	if (FORME == 0)
		ft_getforme(game, line);
	if (BOARD_NBLN == 0)
		ft_getboard_init(game, line);
	else
		ft_getboard_updated(game, line);
	ft_getpiece(game, line);
}
