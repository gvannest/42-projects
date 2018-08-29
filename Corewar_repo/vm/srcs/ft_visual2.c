/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:24:08 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 09:16:11 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_is_proc(t_corvisu *visual, int pyr_idx, char inst, int i)
{
	int		c;

	if (pyr_idx != 0)
		c = 7 + pyr_idx;
	else
		c = 14;
	wattron(visual->win_arena, COLOR_PAIR(c));
	mvwprintw(visual->win_arena, i / 64 + 1, (i % 64 + 1) * 3, "%.2hhx", inst);
	wattroff(visual->win_arena, COLOR_PAIR(c));
}

void		ft_is_not_proc(t_corvisu *visual, int pyr_idx, char inst, int i)
{
	if (pyr_idx != 0)
	{
		wattron(visual->win_arena, COLOR_PAIR(pyr_idx));
		mvwprintw(visual->win_arena, i / 64 + 1, (i % 64 + 1) * 3, "%.2hhx",
				inst);
		wattroff(visual->win_arena, COLOR_PAIR(pyr_idx));
	}
	else
		mvwprintw(visual->win_arena, i / 64 + 1, (i % 64 + 1) * 3, "%.2hhx",
				inst);
}
