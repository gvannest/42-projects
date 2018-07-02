/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_visual.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 17:38:25 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/29 19:17:30 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VISUAL_H
# define COREWAR_VISUAL_H

#include <ncurses.h>
#include "corewar_visual.h"

struct		s_corvisu
{
	char	*map_v;
	int		*map_pyr_v;
	int		*map_proc_v;
	int		nb_pyrs_v;
	char	tab_color[MAX_PLAYERS];
}			t_corvisu;


#endif

