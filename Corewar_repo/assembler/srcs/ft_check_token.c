/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:26:06 by srossi            #+#    #+#             */
/*   Updated: 2018/08/01 19:30:01 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_check_token(t_asm *info, t_token *token)
{
	char	type;

	type = token->type;
	if (type == T_DIR_LAB)
		type = T_DIR;
	else if (type == T_IND_LAB)
		type = T_IND;
	if (token->type == T_DIR_LAB || token->type == T_IND_LAB
			|| token->type == T_DIR || token->type == T_IND)
	{
		if ((g_op_tab[info->last_opcode - 1].param_type[info->cur_param - 1]
					& type) == 0)
			ft_error_param(info, token, 3);
	}
}
