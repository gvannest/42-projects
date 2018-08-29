/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 13:47:31 by srossi            #+#    #+#             */
/*   Updated: 2018/08/01 19:28:45 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	char	ft_lab_type(char type, int index, int arg_ln, char *arg)
{
	char	len;
	char	is_label;

	is_label = 0;
	len = 0;
	if (type == 1)
		len = -1;
	while (index < arg_ln + len && ft_strchr(LABEL_CHARS, arg[index]) != 0)
		index++;
	if (index == arg_ln + len)
	{
		if (type == 1)
			is_label = T_LAB;
		else if (type == 2)
			is_label = T_DIR_LAB;
		else if (type == 3)
			is_label = T_IND_LAB;
	}
	return (is_label);
}

int				ft_is_reg(char *arg)
{
	int	index;
	int	arg_ln;
	int i_val;

	arg_ln = ft_strlen(arg);
	index = 0;
	i_val = 0;
	if (arg == 0 || arg[index++] != 'r')
		return (0);
	else
	{
		i_val = ft_atoi(&arg[1]);
		if (i_val < 0 || i_val > 99)
			return (-1);
	}
	while (index < arg_ln)
	{
		if (!ft_isdigit(arg[index]))
			return (0);
		index++;
	}
	return (T_REG);
}

int				ft_is_label(char *arg)
{
	int	index;
	int	arg_ln;
	int	is_label;

	index = 0;
	arg_ln = ft_strlen(arg);
	is_label = 0;
	if (arg != 0 && arg_ln > 1)
	{
		if (arg[arg_ln - 1] == LABEL_CHAR)
			is_label = (int)ft_lab_type(1, index, arg_ln, arg);
		else if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR && arg_ln > 2)
		{
			index = 2;
			is_label = (int)ft_lab_type(2, index, arg_ln, arg);
		}
		else if (arg[0] == LABEL_CHAR)
		{
			index = 1;
			is_label = (int)ft_lab_type(3, index, arg_ln, arg);
		}
	}
	return (is_label);
}

int				ft_is_op(char *arg)
{
	int	is_op;
	int	index;

	is_op = 0;
	index = 0;
	if (arg != 0)
	{
		while (index < NB_INSTR && ft_strcmp(g_op_tab[index].name, arg) != 0)
			index++;
		if (index < NB_INSTR)
			is_op = T_OP;
	}
	return (is_op);
}
