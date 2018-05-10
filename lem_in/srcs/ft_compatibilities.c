/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compatibilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:15:43 by apoque            #+#    #+#             */
/*   Updated: 2018/05/02 18:46:57 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define K set[i[0]][i[2]]

int			ft_are_compatible(int **set, int n)
{
	int	i[5];

	i[0] = -1;
	i[4] = 0;
	while (++i[0] < n && i[4] == 0)
	{
		i[1] = i[0];
		while (++i[1] < n && i[4] == 0)
		{
			i[2] = 0;
			while (set[i[0]][i[2]] != -2 && i[4] == 0)
			{
				i[3] = 0;
				while (set[i[1]][i[3]] != -2 && i[4] == 0)
				{
					if (K == set[i[1]][i[3]] && K >= 0)
						i[4] = 1;
					i[3]++;
				}
				i[2]++;
			}
		}
	}
	return ((i[4] == 0) ? 1 : 0);
}

void		ft_recursive(t_game *game, int **set, int *m, t_ways *way_bis)
{
	int		k;

	k = m[0];
	while (way_bis != NULL)
	{
		set[m[0]] = way_bis->way;
		if (ft_are_compatible(set, m[0] + 1) == 1)
		{
			if (++m[0] == m[1])
				ft_give_path_cost(game, set, m[1], game->nb_ants);
			else
				ft_recursive(game, set, m, (way_bis->next));
		}
		if (k != m[0])
			m[0]--;
		way_bis = way_bis->next;
	}
}

void		ft_compatibilities(t_game *game, t_ways **start, int n)
{
	t_ways	*way;
	t_ways	*way_bis;
	int		**set;
	int		i;
	int		m[2];

	way = *start;
	if (!(set = (int **)malloc(sizeof(int *) * n)))
		exit(EXIT_FAILURE);
	i = 0;
	set[i] = way->way;
	way_bis = way->next;
	i++;
	m[0] = i;
	m[1] = n;
	while (m[1] > 1)
	{
		ft_recursive(game, set, m, way_bis);
		m[1]--;
	}
	if (m[1] == 1)
		ft_give_path_cost(game, set, m[1], game->nb_ants);
	free(set);
}
