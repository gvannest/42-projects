/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_type2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:36:22 by srossi            #+#    #+#             */
/*   Updated: 2018/07/19 17:41:11 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_is_dir(char *arg)
{
	int	index;
	int	arg_ln;
	int	is_dir;

	arg_ln = ft_strlen(arg);
	is_dir = 0;
	index = 1;
	if (arg[index] == '-')
	{
		if (arg_ln == 2)
			return (is_dir);
		index++;
	}
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
	int	arg_ln;
	int	is_ind;

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
