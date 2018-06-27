/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:22:57 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/27 14:54:11 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_visual(t_arena *arena)
{
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	halfdelay();
	printw("Hello World !!!");
	refresh();
	getch();
	endwin();
}

