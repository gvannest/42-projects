/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_path_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:37:21 by apoque            #+#    #+#             */
/*   Updated: 2018/05/03 09:33:43 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				**ft_ordonate_set(int **set, int n)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	j = 1;
	while (n > j)
	{
		if (ft_sizepath(set[i]) > ft_sizepath(set[j]))
		{
			tmp = set[i];
			set[i] = set[j];
			set[j] = tmp;
			i = 0;
			j = 1;
		}
		else
		{
			i++;
			j++;
		}
	}
	return (set);
}

void			ft_change_set(t_game *game, int **set, int n, int cost)
{
	int	i;

	i = 0;
	game->set.cost = cost;
	game->set.found = 1;
	game->set.nb_path = n;
	while (i < n)
	{
		game->set.set[i] = set[i];
		i++;
	}
}

void			ft_give_path_cost(t_game *game, int **set, int n, int ants)
{
	int	paths_used;
	int	cost;

	set = ft_ordonate_set(set, n);
	paths_used = 0;
	cost = ((ft_sizepath(set[0]) == 2) ? 2 : ft_sizepath(set[paths_used]) - 2);
	while (ants > 0 && cost != 2)
	{
		if (paths_used < n - 1)
		{
			while (cost < (ft_sizepath(set[paths_used + 1]) - 2) && ants > 0)
			{
				cost++;
				ants = ants - paths_used - 1;
			}
			paths_used++;
		}
		else
		{
			ants = ants - paths_used - 1;
			cost++;
		}
	}
	if (cost < game->set.cost || game->set.found == 0)
		ft_change_set(game, set, n, cost);
}
