/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 10:38:03 by srossi            #+#    #+#             */
/*   Updated: 2018/06/29 14:58:23 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_token_add_tail(t_token *token, t_token *new_token)
{
	t_token *p_token;

	p_token = token;
	if (new_token != NULL)
	{
		if (token == NULL)
		{
			ft_printf("TESTESTESTESTE");
			token = new_token;
			ft_token_display(new_token);
		}
		else
		{
			while (p_token->next != NULL)
				p_token = p_token->next;
			p_token->next = new_token;
		}
		new_token->next = NULL;
	}
	ft_printf("TESTESTESTESTE");
	ft_token_display(token);
}

void	ft_token_init(t_token *new_token)
{
	new_token->type = -1;
	new_token->s_val = NULL;
	new_token->i_val = -1;
	new_token->pos = -1;
	new_token->line = -1;
	new_token->cl = -1;
	new_token->next = NULL;
}

void	ft_token_load(t_asm *sasm, t_token *token, char *arg, int arg_type)
{
	int pos;
	int arg_ln;

	arg_ln = ft_strlen(arg);
	if (ft_is_label(arg))
		token->s_val = ft_strndup(arg, arg_ln - 1);
	else
		token->s_val = ft_strdup(arg);
	if (arg_type == T_OP)
		token->i_val = ft_get_ival(arg); // recuperer l'opcode si operation dans tableau sinon valeur registre/dir/label/indirect
	token->type = arg_type;
	token->line = sasm->line_nb;
	token->cl = sasm->err_pos;
	pos = sasm->err_pos;
	sasm->err_pos += arg_ln;
}

int ft_get_ival(char *arg)
{
	int ival;
	int index;

	ival = 0;
	index = 0;
	while (index < NB_INSTR && (ft_strcmp(op_tab[index].name, arg) != 0))
		index++;
	if (index < NB_INSTR)
		ival = op_tab[index].opcode;
	return (ival);
}

int	ft_get_opcode(char *arg)
{
	int index;

	index = 0;
	while (index < NB_INSTR)
	{
		if (ft_strcmp(op_tab[index].name, arg) == 0)
			return (op_tab[index].opcode);
		index++;
	}
	return (-1);

}

void	ft_token_free(t_token *token)
{
	ft_strdel(&token->s_val);
	free(token->next);
	free(token);
}

void	ft_token_list_free(t_token *a_token)
{
	t_token *p_token;

	p_token = a_token;
	if (p_token != NULL)
	{
		p_token = a_token->next;
		while (a_token != NULL)
		{
			ft_token_free(a_token);
			a_token = p_token;
			p_token = a_token->next;
		}
		free(p_token);
		free(a_token);
	}
}

int	ft_get_type(char *arg)
{
	int	type;

	type = 0;
	if (ft_is_reg(arg) > 0)
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

t_token *ft_token_new()
{
	t_token *token;

	token = ft_memalloc(sizeof(t_token));
	return (token);
}

void	ft_token_display(t_token *token)
{
	ft_printf("TOKEN :\n");
	ft_printf("    Type : %d\n", token->type);
	if (token->s_val != NULL)
		ft_printf("    S_val : %s\n", token->s_val);
	else
		ft_printf("    S_val : NULL\n");
	ft_printf("    I_val : %d\n", token->i_val);
	ft_printf("    Pos : %d\n", token->pos);
	ft_printf("    Line : %d\n", token->line);
	ft_printf("    Cl : %d\n", token->cl);
}

void	ft_token_add(t_asm *sasm, char *arg, int arg_type)
{
	t_token *new_token;
	
	new_token = ft_token_new();
	ft_token_init(new_token);
	ft_token_display(new_token);
	ft_token_load(sasm, new_token, arg, arg_type);
	ft_token_display(new_token);
	ft_token_add_tail(sasm->atoken, new_token);
//	ft_token_display(sasm->atoken);
}
