/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cycle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:32:02 by msicot            #+#    #+#             */
/*   Updated: 2018/08/27 10:32:06 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_check_live_process(t_arena *arena)
{
	t_proc *proc;

	proc = arena->list_proc;
	while (proc)
	{
		if (proc->flag_live == 0)
		{
			proc = ft_kill_process(&(arena->list_proc), proc);
			arena->nb_live_proc--;
		}
		else
			proc = proc->next;
	}
}

static void		ft_check_live_nbr(t_arena *arena)
{
	if (arena->nb_live_currt >= NBR_LIVE)
		arena->cycle_to_die = arena->cycle_to_die - CYCLE_DELTA;
	else
		arena->nb_round_no_decrease++;
}

static void		ft_check_max(t_arena *arena)
{
	if (arena->nb_round_no_decrease == MAX_CHECKS)
	{
		arena->cycle_to_die = arena->cycle_to_die - CYCLE_DELTA;
		arena->nb_round_no_decrease = 0;
	}
}

void			ft_check_cycle(t_arena *arena)
{
	ft_check_live_process(arena);
	ft_check_live_nbr(arena);
	ft_check_max(arena);
}
