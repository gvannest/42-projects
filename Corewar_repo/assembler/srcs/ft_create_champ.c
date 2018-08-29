/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:01:10 by srossi            #+#    #+#             */
/*   Updated: 2018/08/03 14:02:06 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_create_champ(t_asm *info)
{
	t_token	*p_token;
	int		index;

	index = 0;
	p_token = info->atoken;
	if (!info->comment_f || !info->name_f || (info->nb_instr == 0 && !p_token))
		ft_error_incomplete(info, 1);
	if (info->nb_params_left > 0)
		ft_param_left(info, p_token);
	while (p_token)
	{
		if (index + p_token->arg_size > CHAMP_MAX_SIZE)
			ft_error_param(info, p_token, 5);
		if (p_token->type == T_OP)
			index = ft_param_op(info, p_token, index);
		else if (p_token->type == T_REG)
			index = ft_param_reg(info, p_token, index);
		else if (p_token->type == T_DIR || p_token->type == T_DIR_LAB)
			index = ft_param_dir(info, p_token, index);
		else if (p_token->type == T_IND || p_token->type == T_IND_LAB)
			index = ft_param_ind(info, p_token, index);
		p_token->last_cor_index = info->last_cor_index;
		info->nb_instr = index;
		p_token = p_token->next;
	}
}
