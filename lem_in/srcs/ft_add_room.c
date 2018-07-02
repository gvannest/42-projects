/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:24:47 by srossi            #+#    #+#             */
/*   Updated: 2018/05/03 09:41:05 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int	ft_find_room(t_room *lst_room, t_room *new_room)
{
	while (lst_room && !(ft_strcmp(lst_room->name, new_room->name) == 0) &&
			!(lst_room->x == new_room->x && lst_room->y == new_room->y))
		lst_room = lst_room->next;
	if (lst_room && ft_strcmp(lst_room->name, new_room->name) == 0)
		return (1);
	else if (lst_room && (lst_room->x == new_room->x && lst_room->y ==
				new_room->y))
		return (1);
	return (0);
}

static	int	ft_load_coord(t_room *room, int nb_coord, int l)
{
	((nb_coord == 0) ? room->y = l : 0);
	((nb_coord != 0) ? room->x = l : 0);
	return (0);
}

static	int	ft_load_room(t_room *room, char *line, int room_id)
{
	int			i;
	int			nb_coord;
	long long	l;

	i = ft_strlen(line) - 1;
	room->nb_room = room_id;
	nb_coord = 0;
	while (nb_coord < 2)
	{
		while (ft_isdigit(line[i]))
			i--;
		if (line[i] == ' ' && nb_coord < 2 && (l = ft_atoi(&line[i])) >= 0 &&
				l < INT_MAX)
			((ft_load_coord(room, nb_coord, l) == 0) ? nb_coord++ : 0);
		else
		{
			free(room);
			return (ft_error("room_load"));
		}
		i--;
	}
	room->name = ft_strnew(i + 1);
	ft_strncpy(room->name, line, i + 1);
	return (0);
}

static	int	ft_add_room(t_game *game, t_room *new_room)
{
	if (ft_find_room(game->rooms, new_room) == 1)
		return (-1);
	new_room->next = game->rooms;
	game->rooms = new_room;
	return (0);
}

int			ft_create_room(t_game *game, char *line)
{
	t_room *room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		exit(EXIT_FAILURE);
	((game->f_error == 1) ? game->f_error = 2 : 0);
	ft_bzero(room, sizeof(t_room));
	game->nb_rooms++;
	if (ft_load_room(room, line, game->nb_rooms) < 0)
		return (-1);
	if (ft_add_room(game, room) == -1)
	{
		ft_strdel(&room->name);
		free(room);
	}
	return (0);
}
