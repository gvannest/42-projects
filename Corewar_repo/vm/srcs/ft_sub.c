/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:59:32 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 12:16:23 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_sub(t_arena *arena, t_proc *proc)
{
	int		tab_tmp[2];
	int		*res;
	char	dir_size;

	dir_size = g_optab[proc->opcode_act - 1].dir_oct_size;
	if (!(ft_get_param(arena, proc, proc->pc_act, dir_size)))
		return ;
	res = &(proc->reg[proc->tab_param[2].value - 1]);
	tab_tmp[0] = proc->reg[proc->tab_param[0].value - 1];
	tab_tmp[1] = proc->reg[proc->tab_param[1].value - 1];
	*res = tab_tmp[0] - tab_tmp[1];
	proc->carry = (*res == 0 ? 1 : 0);
}
