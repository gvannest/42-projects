/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 09:31:56 by gvannest          #+#    #+#             */
/*   Updated: 2018/05/01 19:45:49 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_min_path(t_game *game)
{
	int		nb_start;
	int		nb_end;
	t_link	*link;

	nb_start = 0;
	nb_end = 0;
	link = game->room_start->next_map;
	while (link != 0)
	{
		nb_start++;
		link = link->next;
	}
	link = game->room_end->next_map;
	while (link != 0)
	{
		nb_end++;
		link = link->next;
	}
	game->n = ((game->nb_ants < nb_end) ? game->nb_ants : nb_end);
	game->n = ((nb_start < game->n) ? nb_start : game->n);
	ft_init_set(game);
}

static int		ft_add_link(t_game *game, t_pile *current, t_link *link, int k)
{
	t_pile	*new;
	int		i;

	i = 0;
	game->limit++;
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		exit(EXIT_FAILURE);
	ft_bzero(new, sizeof(t_pile));
	if (!(new->path = (t_room**)malloc(sizeof(t_room*) * (k + 2))))
		exit(EXIT_FAILURE);
	ft_bzero(new->path, sizeof(t_room*) * (k + 2));
	while (current->path[i] != 0)
	{
		new->path[i] = current->path[i];
		i++;
	}
	new->path[i] = link->room;
	while (current->next != 0)
		current = current->next;
	current->next = new;
	return (0);
}

static int		ft_add_blocks(t_game *game, t_pile *current)
{
	t_link	*link;
	int		i;
	char	c;

	i = 0;
	while (current->path[i] != 0)
		i++;
	if (current->path[i - 1] == game->room_end)
		return (0);
	link = current->path[i - 1]->next_map;
	while (link)
	{
		i = 0;
		c = 0;
		while (current->path[i] != 0)
			(current->path[i++] == link->room ? c++ : 1);
		(c == 0 ? ft_add_link(game, current, link, i) : 0);
		if (game->limit > 200000 && game->set.found > 0)
			break ;
		link = link->next;
	}
	return (1);
}

static int		ft_init_pile(t_pile **current, t_game *game)
{
	if (!((*current) = (t_pile*)malloc(sizeof(t_pile))))
		exit(EXIT_FAILURE);
	ft_bzero(*current, sizeof(t_pile));
	if (!((*current)->path = (t_room**)malloc(sizeof(t_room*) * 2)))
		exit(EXIT_FAILURE);
	ft_bzero((*current)->path, sizeof(t_room*) * 2);
	(*current)->path[0] = game->room_start;
	return (0);
}

t_ways			*ft_short_path(t_game *game)
{
	t_ways	*list_ways;
	t_pile	*current;
	t_pile	*ptr[2];

	list_ways = 0;
	current = 0;
	ft_init_pile(&current, game);
	ptr[0] = current;
	ft_min_path(game);
	((game->n == 0) ? exit(EXIT_SUCCESS) : 0);
	while (current && (game->k <= game->set.cost - 1 || game->set.found == 0)
			&& game->limit <= 200000)
	{
		if (!ft_add_blocks(game, current))
			ft_new_shortpath(game, current, &list_ways);
		current = current->next;
	}
	while (ptr[0])
	{
		ptr[1] = ptr[0];
		free(ptr[1]->path);
		ptr[0] = ptr[0]->next;
		free(ptr[1]);
	}
	return (list_ways);
}
