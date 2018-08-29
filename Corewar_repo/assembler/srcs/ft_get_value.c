/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:20:50 by srossi            #+#    #+#             */
/*   Updated: 2018/08/01 19:29:14 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_get_opcode(char *arg)
{
	int index;

	index = 0;
	while (index < NB_INSTR)
	{
		if (ft_strcmp(g_op_tab[index].name, arg) == 0)
			return (g_op_tab[index].opcode);
		index++;
	}
	return (-1);
}

int	ft_get_type(char *arg)
{
	int	type;

	type = 0;
	if (ft_is_reg(arg) != 0)
		type = T_REG;
	else if (ft_is_dir(arg) > 0)
		type = T_DIR;
	else if (ft_is_ind(arg) > 0)
		type = T_IND;
	else if (ft_is_op(arg) > 0)
		type = T_OP;
	else
		type = ft_is_label(arg);
	return (type);
}
