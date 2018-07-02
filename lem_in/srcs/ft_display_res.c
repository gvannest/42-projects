/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_res.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:34:20 by apoque            #+#    #+#             */
/*   Updated: 2018/05/08 11:59:02 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_all_arrived(t_game *game)
{
	int	i;
	int	all_arrived;

	i = 0;
	all_arrived = 0;
	while (i < game->nb_ants && all_arrived == 0)
	{
		if (game->ants[i].path[game->ants[i].nb_moves] != -2)
			all_arrived = 1;
		i++;
	}
	if (all_arrived == 0)
		return (1);
	else
		return (0);
}

int			ft_is_last(t_game *game, int ant, int wave)
{
	int	i;
	int	is_last;

	i = ant + 1;
	is_last = 1;
	while (i < game->nb_ants && wave >= game->ants[i].wave && is_last == 1)
	{
		if (game->ants[i].path[game->ants[i].nb_moves + 1] != -1 &&
				game->ants[i].path[game->ants[i].nb_moves + 1] != -3)
			is_last = 0;
		i++;
	}
	if (is_last == 1)
		return (1);
	else
		return (0);
}

char		*ft_n(t_game *game, int ant, t_room *start)
{
	int		room_nb;
	t_room	*room;

	room_nb = game->ants[ant].path[game->ants[ant].nb_moves + 1];
	room = start;
	while (room->nb_room != room_nb && room->next != NULL)
		room = room->next;
	return (room->name);
}

void		ft_move_ant(t_game *game, int ant, int wave)
{
	ft_printf("L%d-%s", game->ants[ant].nb + 1, ft_n(game, ant, game->rooms));
	if (ft_is_last(game, ant, wave) == 0 ||
			(game->ants[ant].wave == 0 && ant + 1 < game->nb_ants &&
			ft_sizepath(game->ants[ant].path) == 2))
		ft_putchar(' ');
	else
		ft_putchar('\n');
	game->ants[ant].nb_moves++;
}

void		ft_display_res(t_game *game)
{
	int	wave;
	int	i;

	wave = 0;
	i = 0;
	ft_putchar('\n');
	while (ft_all_arrived(game) == 0)
	{
		i = 0;
		while (i < game->nb_ants)
		{
			if (wave >= game->ants[i].wave &&
					game->ants[i].path[game->ants[i].nb_moves] != -2)
			{
				ft_move_ant(game, i, wave);
			}
			i++;
		}
		wave++;
	}
}
