/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:32:53 by gvannest          #+#    #+#             */
/*   Updated: 2018/03/07 17:01:45 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static void		ft_free_struct_filler(t_filler *game)
{
	free(BOARD);
	free(MAP_OP);
	free(MAP_ME);
	free(MAPOME);
	free(MAP_SCORE);
	free(PIECE);
}

static void		ft_reinit_filler(t_filler *game)
{
	int i;

	i = 0;
	ft_strdel(&PIECE);
	ft_bzero(BOARD, sizeof(BOARD));
	PIECE_NBLN = 0;
	PIECE_NBCOL = 0;
	PIECE_LNCOUNT = 0;
	COOR_LN = 0;
	COOR_CL = 0;
	TURN_1 = 0;
	TURN_2++;
}

static int		ft_check_input(t_filler *game, char *line)
{
	if (TURN_2 == 0 && TURN_1 == 0 && !ft_strstr(line, "$$$ exec p"))
		return (-1);
	if (TURN_2 == 0 && TURN_1 == 1 && !ft_strstr(line, "Plateau"))
		return (-1);
	if (TURN_2 > 0 && TURN_1 == 0 && !ft_strstr(line, "Plateau"))
		return (-1);
	TURN_1++;
	return (0);
}

static int		ft_read_vm(t_filler *game)
{
	char *line;

	line = 0;
	while (1)
	{
		if (!get_next_line(0, &line) || ft_check_input(game, line) < 0)
		{
			ft_free_struct_filler(game);
			return (-1);
		}
		if (ft_getinfo(game, &line) < 0)
		{
			ft_free_struct_filler(game);
			return (-1);
		}
		if (ft_getinfo(game, &line) == 1)
			break ;
		ft_strdel(&line);
	}
	return (0);
}

int				main(void)
{
	t_filler	game;

	ft_bzero(&game, sizeof(game));
	while (1)
	{
		if (ft_read_vm(&game) < 0)
			return (-1);
		ft_algofiller(&game);
		if (game.coor_ln == 0 && game.coor_cl == 0)
		{
			ft_printf("%d %d\n", 0, 0);
			break ;
		}
		ft_printf("%d %d\n", game.coor_ln, game.coor_cl);
		ft_reinit_filler(&game);
	}
	ft_free_struct_filler(&game);
	return (0);
}
