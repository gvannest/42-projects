/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:27:48 by srossi            #+#    #+#             */
/*   Updated: 2018/08/01 19:29:30 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_load_values_info(t_asm *info, char *arg, t_token *token)
{
	int index_tab;

	index_tab = 0;
	if (token->type == T_OP)
	{
		index_tab = ft_find_index_arg(arg);
		info->nb_params_left = g_op_tab[index_tab].nb_params;
		if (index_tab < 16)
		{
			info->size = ((g_op_tab[index_tab].dir_oct_size == 0) ? 4 : 2);
			info->nb_params = g_op_tab[index_tab].nb_params;
		}
	}
}

void			ft_token_reload(t_asm *info, t_token *token)
{
	token->pos = info->pos;
	token->nb_params = info->nb_params;
	if (token->type == T_DIR || token->type == T_DIR_LAB)
		token->arg_size = info->size;
	else if (token->type == T_IND || token->type == T_IND_LAB)
		token->arg_size = 2;
	else if (token->type != T_LAB)
		token->arg_size = 1;
	token->line = info->line_nb;
	token->cl = info->start;
	token->last_op_pos = info->last_op_pos;
	--info->comma_f;
}

static	void	ft_load_op(t_asm *info, t_token *token, char *arg)
{
	token->opcode = ft_get_opcode(arg);
	info->last_opcode = token->opcode;
	info->last_op_pos = info->pos;
	if (info->line_nb == info->last_op_line && info->last_op_line != -1)
		ft_error_param(info, token, 4);
	info->last_op_line = info->line_nb;
	info->cur_param = 0;
	info->operator_f = 1;
}

static	void	ft_token_subload(t_asm *info, t_token *token)
{
	if (info->nb_params_left <= 0)
		ft_error_param(info, token, 2);
	if (token->type == T_DIR || token->type == T_REG)
	{
		token->i_val = ft_atoi(&token->s_val[1]);
		if (token->type == T_REG && (token->i_val < 0 || token->i_val > 99))
			ft_error_param(info, token, 4);
	}
	else if (token->type == T_IND)
		token->i_val = ft_atoi(token->s_val);
	info->nb_param++;
	info->cur_param++;
	info->nb_params_left--;
}

void			ft_token_load(t_asm *info, t_token *token, char *arg)
{
	int arg_ln;

	arg_ln = ft_strlen(arg);
	token->type = ft_get_type(arg);
	if (token->type == 0)
		ft_error_param(info, token, 6);
	else if (token->type == -1)
		ft_error_param(info, token, 4);
	token->s_val = ft_strdup(arg);
	if (token->type == T_OP || token->type == T_LAB)
	{
		if (info->nb_params_left > 0)
			ft_error_param(info, token, 1);
		if (token->type == T_OP)
			ft_load_op(info, token, arg);
	}
	else if (token->type == T_IND || token->type == T_IND_LAB
			|| token->type == T_DIR_LAB || token->type == T_DIR
			|| token->type == T_REG)
		ft_token_subload(info, token);
}
