/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_champ_param.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:37:59 by srossi            #+#    #+#             */
/*   Updated: 2018/08/03 16:36:55 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_param_left(t_asm *info, t_token *p_token)
{
	if (info->comma_f == 1)
		ft_error_incomplete(info, 2);
	else if (info->comma_f <= 0)
		ft_error_param(info, p_token, 1);
}

int		ft_param_op(t_asm *info, t_token *p_token, int index)
{
	ft_load_ocp(p_token);
	p_token->arg_size = 1;
	info->tab[index++] = p_token->opcode;
	if (p_token->nb_params > 1)
	{
		info->tab[index++] = p_token->ocp;
		p_token->arg_size++;
	}
	else if (p_token->opcode == 0x10)
		info->tab[index++] = p_token->ocp;
	info->last_cor_index = index;
	return (index);
}

int		ft_param_dir(t_asm *info, t_token *p_token, int index)
{
	if (p_token->arg_size == 2)
		ft_load_short((short)p_token->i_val, &info->tab[index]);
	else if (p_token->arg_size == 4)
		ft_load_int((int)p_token->i_val, &info->tab[index]);
	index += p_token->arg_size;
	return (index);
}

int		ft_param_ind(t_asm *info, t_token *p_token, int index)
{
	ft_load_short((short)p_token->i_val, &info->tab[index]);
	index += p_token->arg_size;
	return (index);
}

int		ft_param_reg(t_asm *info, t_token *p_token, int index)
{
	p_token->arg_size = 1;
	info->tab[index++] = p_token->i_val;
	return (index);
}
