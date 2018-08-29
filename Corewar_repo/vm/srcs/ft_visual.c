/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:56:58 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 09:17:27 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_cycle_per_sec(float *cycle_sec, int key, t_corvisu *visual)
{
	if (*cycle_sec <= 990.0 && key == 'r')
		*cycle_sec = *cycle_sec + 10.0;
	else if (*cycle_sec <= 999.0 && key == 'e')
		*cycle_sec = *cycle_sec + 1.0;
	else if (*cycle_sec >= 1.0 && key == 'w')
		*cycle_sec = (*cycle_sec > 1.0 ? *cycle_sec - 1.0 : 1.0);
	else if (*cycle_sec >= 10.0 && key == 'q')
		*cycle_sec = (*cycle_sec == 10.0 ? 1.0 : *cycle_sec - 10.0);
	mvwprintw(visual->win_info_game, 1, 29, "%4d", (int)(*cycle_sec));
	wrefresh(visual->win_info_game);
}

static void	ft_pause_vm(float *cycle_sec, t_corvisu *visual)
{
	int			key;
	static char p = 0;
	int			timer;

	key = -1;
	timer = (int)((1.0 / *cycle_sec) * 1000.0);
	if (p == 0)
	{
		while (key != ' ')
		{
			key = getch();
			if (key == 'r' || key == 'e' || key == 'w' || key == 'q')
				ft_cycle_per_sec(cycle_sec, key, visual);
		}
		p = 1;
	}
	else if (p == 1)
	{
		timeout(timer);
		key = getch();
		p = (key == ' ' ? 0 : 1);
		if (key == 'r' || key == 'e' || key == 'w' || key == 'q')
			ft_cycle_per_sec(cycle_sec, key, visual);
	}
}

void		ft_visual(t_arena *arena, t_corvisu *visual)
{
	int			i;
	static char f;

	f = 0;
	i = 0;
	(f == 0 ? ft_infogame_fix(arena, visual, &f) : 0);
	ft_info_game(arena, visual);
	ft_info_player(arena, visual);
	while (i < MEM_SIZE)
	{
		if (arena->map_process[i] != 0)
			ft_is_proc(visual, arena->map_pyr[i], arena->map[i], i);
		else
			ft_is_not_proc(visual, arena->map_pyr[i], arena->map[i], i);
		i++;
	}
	wrefresh(visual->win_arena);
	wrefresh(visual->win_info_game);
	wrefresh(visual->win_info_pyrs);
	ft_pause_vm(&(arena->cycle_sec), visual);
}
