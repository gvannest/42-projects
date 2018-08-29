/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getparam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 11:25:30 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 12:09:52 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_verif_reg(t_param *tab)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (tab[i].type == T_REG && (tab[i].value < 1 || tab[i].value > 16))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_ocp(t_param *tp, char *ocp_valid, char opcode)
{
	int i;

	i = 0;
	while (i < g_optab[opcode - 1].nb_params)
	{
		if ((g_optab[opcode - 1].param_type[i] & tp[i].type) == 0)
			return (0);
		i++;
	}
	if (!ft_verif_reg(tp))
		return (0);
	*ocp_valid = 1;
	return (1);
}

static int	ft_get_param_value(char *map, t_param *tab, int pc)
{
	int i;

	i = 0;
	tab[0].value = (int)ft_read_memory(map, pc + 2, tab[0].size);
	tab[1].value = (int)ft_read_memory(map, pc + 2 + tab[0].size,
			tab[1].size);
	tab[2].value = (int)ft_read_memory(map, pc + 2 + tab[0].size + tab[1].size,
			tab[2].size);
	while (i < 3)
	{
		if (tab[i].type == T_REG && (tab[i].value < 1 || tab[i].value > 16))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_fill_tabparam(t_param *tab, char ocp, char dir_size)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if ((ocp >> (6 - 2 * i) & 0x03) == 1)
		{
			tab[i].type = T_REG;
			tab[i].size = 1;
		}
		else if ((ocp >> (6 - 2 * i) & 0x03) == 2)
		{
			tab[i].type = T_DIR;
			tab[i].size = 4 - 2 * dir_size;
		}
		else if ((ocp >> (6 - 2 * i) & 0x03) == 3)
		{
			tab[i].type = T_IND;
			tab[i].size = 2;
		}
		i++;
	}
}

int			ft_get_param(t_arena *arena, t_proc *proc, int pc, char dir_size)
{
	int		i;

	i = 0;
	proc->ocp = (char)ft_read_memory(arena->map, pc + 1, 1);
	ft_fill_tabparam(proc->tab_param, proc->ocp, dir_size);
	if (!(ft_get_param_value(arena->map, proc->tab_param, pc)))
		return (0);
	if (!ft_check_ocp(proc->tab_param, &(proc->ocp_valid), proc->opcode_act))
		return (0);
	return (1);
}
