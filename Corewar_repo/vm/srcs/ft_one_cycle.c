/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 08:56:09 by msicot            #+#    #+#             */
/*   Updated: 2018/08/28 09:00:58 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tab_functions.h"
#define G_TAB g_tab_function[i].o

void			ft_one_cycle(t_arena *arena, t_proc *proc)
{
	int	i;

	while (proc)
	{
		if (proc->nb_cycle_before_op > 1)
			proc->nb_cycle_before_op--;
		else
		{
			i = 0;
			while (i < 16)
			{
				if (proc->opcode_act == G_TAB && proc->opcode_valid == 1)
				{
					g_tab_function[i].f_inst(arena, proc);
					break ;
				}
				i++;
			}
			if (proc->jump != 1)
				ft_move_process(arena->map_process, proc, proc->ocp);
			ft_next_opcode(arena, proc);
			ft_reinit_param(proc);
		}
		proc = proc->next;
	}
}
