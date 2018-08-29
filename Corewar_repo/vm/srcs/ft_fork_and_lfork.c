/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:40:04 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 08:53:59 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			ft_fork_and_lfork(t_arena *arena, t_proc *proc,
		char flag_idx)
{
	int		direct;
	int		index;
	t_proc	*proc_fork;

	index = 0;
	direct = (int)ft_read_memory(arena->map, proc->pc_act + 1, IND_SIZE);
	ft_calc_index(&index, direct, proc->pc_act, flag_idx);
	ft_create_proc(arena, proc, index);
	proc_fork = arena->list_proc;
	if (proc_fork->opcode_valid == 1)
		proc_fork->nb_cycle_before_op--;
	else
		ft_move_process(arena->map_process, proc_fork, proc_fork->ocp);
}

void				ft_fork(t_arena *arena, t_proc *proc)
{
	ft_fork_and_lfork(arena, proc, 1);
}

void				ft_lfork(t_arena *arena, t_proc *proc)
{
	ft_fork_and_lfork(arena, proc, 0);
}
