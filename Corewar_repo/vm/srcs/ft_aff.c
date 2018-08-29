/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:52:55 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 12:08:50 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_aff(t_arena *arena, t_proc *proc)
{
	unsigned char	c;
	char			dir_size;

	dir_size = g_optab[proc->opcode_act - 1].dir_oct_size;
	if (!(ft_get_param(arena, proc, proc->pc_act, dir_size)))
		return ;
	c = (unsigned char)(proc->reg[proc->tab_param[0].value - 1]);
	ft_putchar(c);
	proc->carry = (c == 0 ? 1 : 0);
}
