/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_visual.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 17:38:25 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/27 11:00:37 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VISUAL_H
# define COREWAR_VISUAL_H

# include <ncurses.h>

typedef struct		s_corvisu
{
	WINDOW	*win_arena;
	WINDOW	*win_info_game;
	WINDOW	*win_info_pyrs;
	WINDOW	*win_winner;
}					t_corvisu;

#endif
