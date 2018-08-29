/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi_and_lldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:06:50 by msicot            #+#    #+#             */
/*   Updated: 2018/08/28 12:10:46 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_loop_ldi(char *map, int *tab_tmp, t_proc *proc, char flag_idx)
{
	int k;
	int i;

	i = 0;
	while (i < 2)
	{
		if (proc->tab_param[i].type == T_REG)
			tab_tmp[i] = proc->reg[proc->tab_param[i].value - 1];
		else if (proc->tab_param[i].type == T_DIR)
			tab_tmp[i] = proc->tab_param[i].value;
		else if (proc->tab_param[i].type == T_IND)
		{
			ft_calc_index(&k, proc->tab_param[i].value, proc->pc_act,
					flag_idx);
			tab_tmp[i] = (int)ft_read_memory(map, k, REG_SIZE);
		}
		i++;
	}
}

static void	ft_ldi_and_lldi(t_arena *arena, t_proc *proc, char flag_idx)
{
	int		*res;
	int		idx;
	int		tab_tmp[2];
	char	dir_size;

	dir_size = g_optab[proc->opcode_act - 1].dir_oct_size;
	if (!(ft_get_param(arena, proc, proc->pc_act, dir_size)))
		return ;
	ft_loop_ldi(arena->map, tab_tmp, proc, flag_idx);
	ft_calc_index(&idx, tab_tmp[0] + tab_tmp[1], proc->pc_act, flag_idx);
	res = &(proc->reg[proc->tab_param[2].value - 1]);
	*res = (int)ft_read_memory(arena->map, idx, REG_SIZE);
	proc->carry = (*res == 0 ? 1 : 0);
}

void		ft_ldi(t_arena *arena, t_proc *proc)
{
	ft_ldi_and_lldi(arena, proc, 1);
}

void		ft_lldi(t_arena *arena, t_proc *proc)
{
	ft_ldi_and_lldi(arena, proc, 0);
}
