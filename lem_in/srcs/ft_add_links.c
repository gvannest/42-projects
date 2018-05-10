/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:25:26 by srossi            #+#    #+#             */
/*   Updated: 2018/05/03 09:40:38 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int	ft_find_link(t_link *link, char *name)
{
	while (link && (ft_strcmp(link->room->name, name) != 0))
		link = link->next;
	if (link && ft_strcmp(link->room->name, name) == 0)
		return (1);
	return (0);
}

static	int	ft_add_link(t_room *ptr, char **rooms[2], t_link *link1,
		t_link *link2)
{
	t_room	*ptr_cpy;
	char	*room1;
	char	*room2;

	room1 = *rooms[0];
	room2 = *rooms[1];
	ptr_cpy = ptr;
	if (ft_find_link(ptr_cpy->next_map, room1))
		return (-1);
	link1->room = ptr;
	while (ptr_cpy->next && ft_strcmp(ptr_cpy->name, room1) != 0)
		ptr_cpy = ptr_cpy->next;
	if (ft_strcmp(ptr_cpy->name, room1) != 0)
		return (ft_error("link_room1"));
	link2->room = ptr_cpy;
	link1->next = ptr_cpy->next_map;
	ptr_cpy->next_map = link1;
	ptr_cpy = ptr;
	while (ptr_cpy->next && ft_strcmp(ptr_cpy->name, room2) != 0)
		ptr_cpy = ptr_cpy->next;
	if (ft_strcmp(ptr_cpy->name, room2) != 0)
		return (ft_error("link_room2"));
	link2->next = ptr->next_map;
	ptr->next_map = link2;
	return (0);
}

static	int	ft_add_bounds(t_game *game, char **rooms[2], t_link *link1,
		t_link *link2)
{
	t_room	*ptr;
	char	*room1;
	char	*room2;
	char	*tmp;

	room1 = *rooms[0];
	room2 = *rooms[1];
	ptr = game->rooms;
	while (ptr && ft_strcmp(ptr->name, room1) != 0 &&
			ft_strcmp(ptr->name, room2) != 0)
		ptr = ptr->next;
	if (!ptr)
		return (ft_error("room_unfound"));
	if (ft_strcmp(ptr->name, room1) == 0)
	{
		tmp = *rooms[0];
		*rooms[0] = *rooms[1];
		*rooms[1] = tmp;
		return (ft_add_link(ptr, rooms, link2, link1));
	}
	else if (ft_strcmp(ptr->name, room2) == 0)
		return (ft_add_link(ptr, rooms, link1, link2));
	return (0);
}

static	int	ft_free_split(char **tab_split)
{
	int i;

	i = 0;
	while (tab_split[i])
	{
		ft_strdel(&tab_split[i]);
		i++;
	}
	free(tab_split);
	return (0);
}

int			ft_create_bounds(t_game *game, char *line)
{
	char	**rooms[2];
	char	**tab_split;
	t_link	*link1;
	t_link	*link2;

	tab_split = ft_strsplit(line, '-');
	rooms[0] = &tab_split[0];
	rooms[1] = &tab_split[1];
	if (ft_strcmp(*rooms[0], *rooms[1]) == 0)
	{
		ft_free_split(tab_split);
		return (ft_error("link_loop"));
	}
	if (!(link1 = ft_memalloc(sizeof(t_link))) ||
			(!(link2 = ft_memalloc(sizeof(t_link)))))
		exit(EXIT_FAILURE);
	if (ft_add_bounds(game, rooms, link1, link2) == -1)
	{
		ft_free_split(tab_split);
		free(link1);
		free(link2);
		return (-1);
	}
	ft_free_split(tab_split);
	return (0);
}
