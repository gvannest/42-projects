/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:32:14 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 12:16:48 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_loop_sti(char *map, int *tab_tmp, t_proc *proc)
{
	int i;
	int k;

	i = 1;
	while (i < 3)
	{
		if (proc->tab_param[i].type == T_REG)
			tab_tmp[i] = proc->reg[proc->tab_param[i].value - 1];
		else if (proc->tab_param[i].type == T_DIR)
			tab_tmp[i] = proc->tab_param[i].value;
		else if (proc->tab_param[i].type == T_IND)
		{
			ft_calc_index(&k, proc->tab_param[i].value, proc->pc_act, 1);
			tab_tmp[i] = (int)ft_read_memory(map, k, REG_SIZE);
		}
		i++;
	}
}

void			ft_sti(t_arena *arena, t_proc *proc)
{
	int		*res;
	int		idx;
	int		tab_tmp[3];
	char	dir_size;

	dir_size = g_optab[proc->opcode_act - 1].dir_oct_size;
	if (!(ft_get_param(arena, proc, proc->pc_act, dir_size)))
		return ;
	ft_loop_sti(arena->map, tab_tmp, proc);
	ft_calc_index(&idx, tab_tmp[1] + tab_tmp[2], proc->pc_act, 1);
	res = &(proc->reg[proc->tab_param[0].value - 1]);
	ft_write_memory(arena->map, *res, idx, REG_SIZE);
	ft_update_map_pyr(arena->map_pyr, proc->pc_act, idx, REG_SIZE);
}
