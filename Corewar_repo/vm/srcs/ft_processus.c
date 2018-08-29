/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:10:01 by msicot            #+#    #+#             */
/*   Updated: 2018/08/28 12:12:28 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_move_noocp(t_proc *proc)
{
	if (proc->opcode_act == 0x01)
		proc->pc_act = (proc->pc_act + 5) % MEM_SIZE;
	else
		proc->pc_act = (proc->pc_act + 3) % MEM_SIZE;
}

static void	ft_move_ocp(t_proc *proc, char ocp)
{
	unsigned int	i;
	short int		k;
	unsigned char	tab[3];

	i = 0;
	k = 1;
	if (proc->ocp_valid == 1)
	{
		tab[0] = ocp >> 6 & 0x03;
		tab[1] = ocp >> 4 & 0x03;
		tab[2] = ocp >> 2 & 0x03;
		while (i < 3)
		{
			if (tab[i] == 0x01)
				k = k + 1;
			else if (tab[i] == 0x02)
				k = k + 4 - 2 * g_optab[proc->opcode_act - 1].dir_oct_size;
			else if (tab[i] == 0x03)
				k = k + 2;
			i++;
		}
	}
	proc->pc_act = (proc->pc_act + k + 1) % MEM_SIZE;
}

void		ft_move_process(int *map_proc, t_proc *proc, char ocp)
{
	map_proc[proc->pc_act % MEM_SIZE] = 0;
	if (proc->opcode_valid == 1)
	{
		if (ocp == -1)
			ft_move_noocp(proc);
		else
			ft_move_ocp(proc, ocp);
	}
	else
		proc->pc_act = (proc->pc_act + 1) % MEM_SIZE;
	map_proc[proc->pc_act % MEM_SIZE] = 1;
}

t_proc		*ft_kill_process(t_proc **begin_list, t_proc *proc_to_kill)
{
	t_proc *ptr;

	ptr = *begin_list;
	if (proc_to_kill == *begin_list)
	{
		*begin_list = (*begin_list)->next;
		ptr = *begin_list;
	}
	else
	{
		while (ptr->next != proc_to_kill)
			ptr = ptr->next;
		ptr->next = proc_to_kill->next;
		ptr = ptr->next;
	}
	free(proc_to_kill);
	proc_to_kill = NULL;
	return (ptr);
}
