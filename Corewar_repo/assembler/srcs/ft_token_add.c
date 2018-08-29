/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 10:38:03 by srossi            #+#    #+#             */
/*   Updated: 2018/08/03 14:02:56 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	ft_pos_increment(t_asm *info, t_token *new_token)
{
	info->pos += new_token->arg_size;
	if (new_token->opcode > 0)
		info->last_opcode = new_token->opcode;
	if (new_token->type == T_OP && (new_token->nb_params > 1
				|| (ft_strequ(new_token->s_val, "aff"))))
		info->pos++;
}

void			ft_token_init(t_token *new_token)
{
	new_token->type = -1;
	new_token->s_val = NULL;
	new_token->i_val = -1;
	new_token->opcode = -1;
	new_token->ocp = 0;
	new_token->pos = -1;
	new_token->line = -1;
	new_token->cl = -1;
	new_token->arg_size = 0;
	new_token->nb_params = 0;
	new_token->next = NULL;
}

void			ft_token_add_tail(t_token **token, t_token *new_token)
{
	t_token *p_token;

	p_token = *token;
	if (new_token != NULL)
	{
		if (p_token == NULL)
			*token = new_token;
		else
		{
			while (p_token->next != NULL)
				p_token = p_token->next;
			p_token->next = new_token;
		}
		new_token->next = NULL;
	}
}

void			ft_token_add(t_asm *info, char *arg)
{
	t_token *new_token;
	char	*arg_trim;

	if (info->path == NULL)
		info->path = ft_strdup("");
	new_token = ft_memalloc(sizeof(t_token));
	arg_trim = ft_strtrim(arg);
	ft_token_init(new_token);
	ft_token_load(info, new_token, arg_trim);
	ft_load_values_info(info, arg_trim, new_token);
	ft_token_reload(info, new_token);
	ft_check_token(info, new_token);
	ft_token_add_tail(&info->atoken, new_token);
	ft_pos_increment(info, new_token);
	ft_strdel(&arg_trim);
}
