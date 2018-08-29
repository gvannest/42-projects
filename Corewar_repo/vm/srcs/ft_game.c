/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:59:16 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 08:53:12 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_winner_novisu(t_player *tab_pyr, int nb_pyrs, int winner)
{
	int i;

	i = 0;
	if (winner == 0)
		ft_printf("You forgot to say live. You Morons...\n");
	else
	{
		winner = nb_pyrs == 1 ? tab_pyr[0].pyr_nbr : winner;
		{
			while (i < nb_pyrs)
			{
				if (tab_pyr[i].pyr_nbr == winner)
					ft_printf("Player %d, '%s' , has won the game!\n", winner,
							tab_pyr[i].pyr_name);
				i++;
			}
		}
	}
}

static void	ft_intro_contestants(t_player *tab_pyr, t_corvisu *visual,
		int nb_pyrs, char v)
{
	int i;

	i = 0;
	if (v == 1)
		ft_init_visual(visual);
	else
	{
		ft_printf("The champions aaaaaaare ....\n");
		while (i < nb_pyrs)
		{
			ft_printf("Player %d, weighing %d bytes :\n", tab_pyr[i].pyr_nbr,
					tab_pyr[i].nb_inst);
			ft_printf("     Name : %s\n", tab_pyr[i].pyr_name);
			ft_printf("     Comment : %s\n\n", tab_pyr[i].comment);
			i++;
		}
	}
}

void		ft_game(t_arena *arena, t_corvisu *visual, char v)
{
	(arena->dump_f != 1 ? ft_intro_contestants(arena->tab_pyr, visual,
			arena->nb_pyrs, v) : 0);
	while (arena->nb_live_proc > 0 && arena->cycle_to_die > 0)
	{
		while (arena->nb_cycle_current < arena->cycle_to_die)
		{
			if (v == 1)
				ft_visual(arena, visual);
			if (arena->dump_f == 1 && arena->nb_cycle == arena->dump_nb)
				ft_dump_mem(arena);
			ft_one_cycle(arena, arena->list_proc);
			arena->nb_cycle++;
			arena->nb_cycle_current++;
		}
		ft_check_cycle(arena);
		ft_reinit_cycle(arena, arena->list_proc);
	}
	if (v == 1)
		ft_winner_visu(arena->tab_pyr, arena->nb_pyrs, visual,
				arena->last_live_pyr);
	else if (v != 1)
		ft_winner_novisu(arena->tab_pyr, arena->nb_pyrs,
				arena->last_live_pyr);
}
