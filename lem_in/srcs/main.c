/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:07:28 by srossi            #+#    #+#             */
/*   Updated: 2018/05/02 19:45:47 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int	ft_free_game(t_game *game, t_ways *list_ways)
{
	if (game->f_error > 0)
		ft_free_lines(game->lines);
	if (game->f_error > 1)
		ft_free_rooms(game->rooms);
	if (game->f_error > 2)
		ft_free_ants(game, game->ants);
	if (game->f_error > 3)
		free(game->set.set);
	if (game->f_error > 4)
		ft_free_listways(list_ways);
	return (0);
}

static	int	ft_add_linetogame(char **line, t_game *game, int i)
{
	if (i == 0)
	{
		ft_add_line(*line, game);
		if (game->f_error == 0)
			game->f_error = 1;
		ft_strdel(line);
	}
	if (i == -2)
	{
		if (game->f_error > 0)
			ft_strdel(line);
		return (-2);
	}
	return (0);
}

static	int	ft_get_info(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	while (i == 0 && get_next_line(0, &line))
	{
		i = ft_parse(line, game);
		if (ft_add_linetogame(&line, game, i) == -2)
			return (-2);
	}
	if (ft_last_check(game) == -2)
	{
		((game->f_error > 0) ? free(line) : 0);
		return (-2);
	}
	ft_add_lants(game);
	((game->f_error == 2) ? game->f_error = 3 : 0);
	((game->f_error > 0) ? ft_strdel(&line) : 0);
	return (0);
}

int			main(void)
{
	t_game	game;
	t_ways	*list_ways;

	list_ways = NULL;
	ft_bzero(&game, sizeof(t_game));
	if (ft_get_info(&game) == -2)
	{
		ft_free_game(&game, list_ways);
		return (-1);
	}
	ft_display_lines(&game);
	if (!(list_ways = ft_short_path(&game)))
	{
		game.f_error = 4;
		ft_free_game(&game, list_ways);
		return (-1);
	}
	game.f_error = 5;
	ft_select_path(&game);
	ft_display_res(&game);
	ft_free_game(&game, list_ways);
	return (0);
}
