/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_fix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:15:24 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 17:28:07 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_infopyr_fix(t_arena *arena, t_corvisu *visual)
{
	int p;

	p = 0;
	while (p < arena->nb_pyrs)
	{
		wattron(visual->win_info_pyrs, COLOR_PAIR(p + 1));
		mvwprintw(visual->win_info_pyrs, 1 + 10 * p, 2, "Player %d",
				arena->tab_pyr[p].pyr_nbr);
		mvwprintw(visual->win_info_pyrs, 3 + 10 * p, 5, "Name : %s",
				arena->tab_pyr[p].pyr_name);
		mvwprintw(visual->win_info_pyrs, 10 * p + 5, 5, "Nombre de live : ");
		wattroff(visual->win_info_pyrs, COLOR_PAIR(p + 1));
		p++;
	}
	mvwprintw(visual->win_info_pyrs, 40, 2, "------------------------------");
	mvwprintw(visual->win_info_pyrs, 40, 30, "---------------------------");
	wattron(visual->win_info_pyrs, A_BOLD);
	mvwprintw(visual->win_info_pyrs, 42, 2, "Current winner :       ");
	wattroff(visual->win_info_pyrs, A_BOLD);
}

void		ft_infogame_fix(t_arena *arena, t_corvisu *visual, char *f)
{
	int p;

	p = 0;
	wattron(visual->win_info_game, A_BOLD);
	mvwprintw(visual->win_info_game, 1, 2, "Number of cycles / sec : ");
	mvwprintw(visual->win_info_game, 3, 2, "Usage :\n");
	mvwprintw(visual->win_info_game, 3, 12, "q   -10\n");
	mvwprintw(visual->win_info_game, 4, 12, "w   -1\n");
	mvwprintw(visual->win_info_game, 5, 12, "e   +1\n");
	mvwprintw(visual->win_info_game, 6, 12, "r   +10\n");
	mvwprintw(visual->win_info_game, 1, 66, "Cycle to die   : ");
	mvwprintw(visual->win_info_game, 3, 66, "Cycle current  : ");
	mvwprintw(visual->win_info_game, 5, 66, "Cycle total    : ");
	mvwprintw(visual->win_info_game, 1, 132,
			"Number of live current period : ");
	mvwprintw(visual->win_info_game, 3, 132, "Number of live total : ");
	mvwprintw(visual->win_info_game, 5, 132, "Number of process alive : ");
	wattroff(visual->win_info_game, A_BOLD);
	ft_infopyr_fix(arena, visual);
	*f = 1;
}

void		ft_info_game(t_arena *arena, t_corvisu *visual)
{
	wattron(visual->win_info_game, A_BOLD);
	mvwprintw(visual->win_info_game, 1, 29, "%4d", (int)(arena->cycle_sec));
	mvwprintw(visual->win_info_game, 1, 85, "%6d", arena->cycle_to_die);
	mvwprintw(visual->win_info_game, 3, 85, "%6d", arena->nb_cycle_current);
	mvwprintw(visual->win_info_game, 5, 85, "%6d", arena->nb_cycle);
	mvwprintw(visual->win_info_game, 1, 165, "%6d", arena->nb_live_currt);
	mvwprintw(visual->win_info_game, 3, 165, "%6d", arena->nb_live_tot);
	mvwprintw(visual->win_info_game, 5, 165, "%6d", arena->nb_live_proc);
	wattroff(visual->win_info_game, A_BOLD);
}

void		ft_info_player(t_arena *arena, t_corvisu *visual)
{
	int p;

	p = 0;
	while (p < arena->nb_pyrs)
	{
		wattron(visual->win_info_pyrs, COLOR_PAIR(p + 1));
		mvwprintw(visual->win_info_pyrs, 10 * p + 5, 20, "%6d",
				arena->tab_pyr[p].pyr_nb_live);
		wattroff(visual->win_info_pyrs, COLOR_PAIR(p + 1));
		p++;
	}
	p = 0;
	if (arena->last_live_pyr != 0)
	{
		while (arena->tab_pyr[p].pyr_nbr != arena->last_live_pyr)
			p++;
		wattron(visual->win_info_pyrs, COLOR_PAIR(p + 1));
		mvwprintw(visual->win_info_pyrs, 42, 20, "Player %4d",
				arena->last_live_pyr);
		wattroff(visual->win_info_pyrs, COLOR_PAIR(p + 1));
	}
}
