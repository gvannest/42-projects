/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:41:45 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/29 15:27:31 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		next_process(t_arena *arena, int p)
{
	t_proc *ptr;
	t_proc *new_proc;

	ptr = arena->list_proc;
	if (!(new_proc = (t_proc*)ft_memalloc(sizeof(t_proc))))
		ft_error_vm(0, "Error : malloc failed","Line 22 in ft_processus.c",0);
	ft_bzero(new_proc->reg, sizeof(int) * REG_NUMBER);
	new_proc->reg[0] = arena->tab_pyr[p].pyr_nbr;
	new_proc->p_nbr = p + 1;
	new_proc->pc_act = 0 + p * MEM_SIZE / arena->nb_pyrs;
	arena->map_process[p * MEM_SIZE / arena->nb_pyrs] = new_proc->p_nbr;
	while (ptr->next != 0)
		ptr = ptr->next;
	ptr->next = new_proc;
}

static void		first_process(t_arena *arena)
{
	t_proc *proc;

	if (!(proc = (t_proc*)ft_memalloc(sizeof(t_proc))))
		ft_error_vm(0, "Error : malloc failed","Line 30 in ft_processus.c",0);
	ft_bzero(proc->reg, sizeof(int) * REG_NUMBER);
	proc->reg[0] = arena->tab_pyr[0].pyr_nbr;
	proc->p_nbr = 1;
	proc->pc_act = 0;
	arena->map_process[0] = proc->p_nbr;
	arena->list_proc = proc;
	arena->nb_live_proc = 1;
}

void		ft_init_process(t_arena *arena)
{
	int p;

	p = 1;
	first_process(arena);
	while (p < arena->nb_pyrs)
	{
		next_process(arena, p);
		p++;
	}
}

