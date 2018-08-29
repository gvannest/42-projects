/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:31:06 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 12:10:21 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_ldandlld(t_arena *arena, t_proc *proc, char flag_idx)
{
	int		k;
	int		*res;
	char	dir_size;
	char	size_to_read;

	size_to_read = (flag_idx == 1 ? REG_SIZE : IND_SIZE);
	dir_size = g_optab[proc->opcode_act - 1].dir_oct_size;
	if (!(ft_get_param(arena, proc, proc->pc_act, dir_size)))
		return ;
	res = &(proc->reg[proc->tab_param[1].value - 1]);
	if (proc->tab_param[0].type == T_DIR)
		*res = proc->tab_param[0].value;
	else if (proc->tab_param[0].type == T_IND)
	{
		ft_calc_index(&k, proc->tab_param[0].value, proc->pc_act, flag_idx);
		*res = (int)ft_read_memory(arena->map, k, size_to_read);
	}
	proc->carry = (*res == 0 ? 1 : 0);
}

void			ft_load(t_arena *arena, t_proc *proc)
{
	ft_ldandlld(arena, proc, 1);
}

void			ft_lld(t_arena *arena, t_proc *proc)
{
	ft_ldandlld(arena, proc, 0);
}
