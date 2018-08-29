/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 10:59:44 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 08:50:54 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_fill_map_pyr(t_arena *arena)
{
	int		p;
	int		i;

	p = 0;
	while (p < arena->nb_pyrs)
	{
		i = 0;
		while (i < arena->tab_pyr[p].nb_inst)
		{
			arena->map_pyr[i + p * MEM_SIZE / arena->nb_pyrs] = p + 1;
			i++;
		}
		p++;
	}
}

static void		ft_fill_map(t_arena *arena)
{
	int		i;

	i = 0;
	while (i < arena->nb_pyrs)
	{
		ft_memcpy(arena->map + i * MEM_SIZE / arena->nb_pyrs,
				arena->tab_pyr[i].champ, arena->tab_pyr[i].nb_inst);
		i++;
	}
}

void			ft_fill_game(t_arena *arena)
{
	ft_fill_map(arena);
	ft_fill_map_pyr(arena);
	ft_init_process(arena);
	arena->cycle_to_die = CYCLE_TO_DIE;
	arena->cycle_sec = 50.0;
}
