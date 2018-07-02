/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:22:57 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/29 19:08:45 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_init_visual(t_arena *arena, t_corvisu *visual)
{
	visual->map_v = arena->map;
	visual->map_pyr_v = arena->map_pyr;
	visual->map_proc_v = arena->map_process;

	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	if(has_colors() == FALSE)
	{
		endwin();
		ft_error_vm(0, "Your terminal does not support color", "", 0);
	}
	start_color();
}

void		ft_visual(t_arena *arena)
{
	printw("%s", arena->map);
	refresh();
	getch();
	endwin();
}

