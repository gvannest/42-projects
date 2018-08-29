/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:53:58 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 09:12:56 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_printwin(t_player *tab_pyr, t_corvisu *visual, int winner, int p)
{
	int len;

	(void)winner;
	len = ft_strlen(tab_pyr[p].pyr_name);
	wattron(visual->win_winner, COLOR_PAIR(p + 1));
	mvwprintw(visual->win_winner, 3, 41, "* * * *\n");
	mvwprintw(visual->win_winner, 4, 36, "* * * \\|O|/ * * *\n");
	mvwprintw(visual->win_winner, 5, 37, "\\o\\o\\o|O|o/o/o/\n");
	mvwprintw(visual->win_winner, 6, 37, "(<><><>O<><><>)\n");
	mvwprintw(visual->win_winner, 7, 37, "'============='\n");
	mvwprintw(visual->win_winner, 12, 45 - (len + 20) / 2,
			"Player \"%s\" has won!\n", tab_pyr[p].pyr_name);
	wattroff(visual->win_winner, COLOR_PAIR(p + 1));
}

static void	ft_printlose(t_corvisu *visual)
{
	mvwprintw(visual->win_winner, 3, 41, "______\n");
	mvwprintw(visual->win_winner, 4, 40, "(( ____ \\----\n");
	mvwprintw(visual->win_winner, 5, 40, "(( _____ \n");
	mvwprintw(visual->win_winner, 6, 40, "(((_____ \n");
	mvwprintw(visual->win_winner, 7, 40, "((____   ----\n");
	mvwprintw(visual->win_winner, 8, 44, "/  /\n");
	mvwprintw(visual->win_winner, 9, 42, " (_(( \n");
	mvwprintw(visual->win_winner, 14, 30, "No one said live, you MORONS!\n");
}

void		ft_winner_visu(t_player *tab_pyr, int nb_pyrs, t_corvisu *visual,
		int winner)
{
	int c;
	int p;

	p = 0;
	visual->win_winner = create_newwin(20, 90, 25, 50);
	while (p < nb_pyrs && tab_pyr[p].pyr_nbr != winner)
		p++;
	if (winner != 0)
		ft_printwin(tab_pyr, visual, winner, p);
	else
		ft_printlose(visual);
	wrefresh(visual->win_winner);
	c = getch();
	while (c != 27)
		c = getch();
	endwin();
}
