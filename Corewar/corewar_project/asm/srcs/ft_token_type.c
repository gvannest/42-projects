/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 13:47:31 by srossi            #+#    #+#             */
/*   Updated: 2018/06/28 16:56:58 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_is_reg(char *arg)
{
	int index;
	int	arg_ln;

	arg_ln = ft_strlen(arg);
	index = 0;
	if (arg == 0 || arg[index++] != 'r' || ft_atoi(&arg[1]) < 0)
		return (0);
	while (index < arg_ln)
	{
		if (!ft_isdigit(arg[index]))
			return (0);
		index++;
	}
	return (T_REG);
}

int	ft_is_label(char *arg)
{
	int	index;
	int arg_ln;
	int is_label;

	index = 0;
	arg_ln = ft_strlen(arg);
	is_label = 0;
	if (arg != 0 && arg_ln > 1)
	{
		if (arg[arg_ln - 1] == LABEL_CHAR)
		{
			while (index < arg_ln - 1 && ft_strchr(LABEL_CHARS, arg[index]) != 0)
				index++;
			if (index == arg_ln - 1)
				is_label = T_LAB;
		}
		else if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR && arg_ln > 2)
		{
			index = 2;
			while (index < arg_ln && ft_strchr(LABEL_CHARS, arg[index]) != 0)
				index++;
			if (index == arg_ln)
				is_label = T_DIR_LAB;
		}
		else if (arg[0] == LABEL_CHAR)
		{
			index = 1;
			while (index < arg_ln && ft_strchr(LABEL_CHARS, arg[index]) != 0)
				index++;
			if (index == arg_ln)
				is_label = T_IND_LAB;
		}
	}
	return (is_label);
}

int	ft_is_dir(char *arg)
{
	int	index;
	int arg_ln;
	int is_dir;

	arg_ln = ft_strlen(arg);
	is_dir = 0;
	index = 1;
	if (arg[index] == '-')
		index++;
	if (arg != 0 && arg[0] == DIRECT_CHAR && arg_ln > 1)
	{
		while (index < arg_ln && ft_isdigit(arg[index]))
			index++;
		if (index == arg_ln)
			is_dir = T_DIR;
	}
	return (is_dir);
}

int	ft_is_ind(char *arg)
{
	int	index;
	int arg_ln;
	int is_ind;

	arg_ln = ft_strlen(arg);
	is_ind = 0;
	index = 0;
	if (arg != 0 && arg_ln > 0)
	{
		if (arg[0] == '-')
			index++;
		while (index < arg_ln && ft_isdigit(arg[index]))
			index++;
		if (index == arg_ln)
			is_ind = T_IND;
	}
	return (is_ind);
}

int	ft_is_op(char *arg)
{
	int is_op;
	int index;

	is_op = 0;
	index = 0;
	if (arg != 0)
	{
		while (index < NB_INSTR && ft_strcmp(op_tab[index].name, arg) != 0)
			index++;
		if (index < NB_INSTR)
			is_op = T_OP;
	}
	return (is_op);
}
