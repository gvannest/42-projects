/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:47:09 by msicot            #+#    #+#             */
/*   Updated: 2018/08/29 12:28:27 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parsing_error(t_asm *info, char *line)
{
	if (info->error == 1)
		ft_dprintf(2, "Error=1 Syntax error at token [TOKEN][%03d:%03d] \
\"%s\"\n", info->line_nb, info->start + 1, info->err_log);
	else if (info->error == 2)
		error_instr(info, line);
	else if (info->error == 3)
		ft_dprintf(2, "Syntax error at token [TOKEN][%03d:%03d] SEPARATOR \
\"%s\"\n", info->line_nb, info->start + 1, line);
	else if (info->error == 4)
		ft_dprintf(2, "Syntax error at token [TOKEN][%03d:%03d] ENDLINE\n"
				, info->line_nb, info->end + 1);
	else if (info->error == 5)
		ft_dprintf(2, "Syntax error at token [TOKEN][%03d:%03d] END \"%s\"\n"
				, info->line_nb, info->end + 1, line);
	else if (info->error == 6)
		ft_dprintf(2, "Lexical error at [%d:%d]\n", info->line_nb,
				info->end + 1);
	if (line != NULL)
		ft_strdel(&line);
	if (info->err_log != NULL)
		ft_strdel(&info->err_log);
	ft_free(info);
	exit(EXIT_FAILURE);
}

void	ft_error_param(t_asm *info, t_token *token, int nb_error)
{
	if (nb_error == 1)
		ft_dprintf(2, "Invalid parameter count for instruction %s\n",
				g_op_tab[info->last_opcode - 1].name);
	else if (nb_error == 2)
		ft_dprintf(2, "Invalid parameter %d type %s for instruction %s\n",
					info->cur_param, ft_type_char(token->type),
					g_op_tab[info->last_opcode - 1].name);
	else if (nb_error == 3)
		ft_dprintf(2, "Invalid parameter %d type %s for instruction %s\n",
					info->cur_param - 1, ft_type_char(token->type),
					g_op_tab[info->last_opcode - 1].name);
	else if (nb_error == 4)
		ft_dprintf(2, "Syntax error at token [TOKEN][%03d:%03d] \
INSTRUCTION \"%s\"\n"
				, info->line_nb, info->start + 1, token->s_val);
	else if (nb_error == 5)
		ft_dprintf(2, "Champion size is too big.\n");
	else if (nb_error == 6)
		ft_dprintf(2, "Lexical error at [%d:%d]\n", info->line_nb,
				info->start + 1);
	ft_free(info);
	exit(EXIT_FAILURE);
}

void	ft_error_incomplete(t_asm *info, int nb_error)
{
	if (nb_error == 1)
		ft_dprintf(2, "Syntax error at token [TOKEN][%03d:%03d] END \"%s\"\n"
				, info->line_nb + 1, 1, "(null)");
	else if (nb_error == 2)
		ft_dprintf(2, "Syntax error at token [TOKEN][%03d:%03d] ENDLINE\n"
				, info->line_nb, info->end + 1);
	ft_free(info);
	exit(EXIT_FAILURE);
}

void	ft_error_length(t_asm *info, int nb_error)
{
	if (nb_error == 1)
		ft_dprintf(2, "Champion name too long (Max length %d)\n",
				PROG_NAME_LENGTH);
	else if (nb_error == 2)
		ft_dprintf(2, "Champion comment too long (Max length %d)\n"
		, COMMENT_LENGTH);
	ft_free(info);
	exit(EXIT_FAILURE);
}

void	ft_error_doubles(t_asm *info, int nb_error)
{
	if (nb_error == 1)
		ft_dprintf(2, "Syntax error at token [TOKEN][%03d:%03d] COMMAND_NAME \
\".name\"\n", info->line_nb, info->start + 1);
	else if (nb_error == 2)
		ft_dprintf(2, "Syntax error at token [TOKEN][%03d:%03d] \
				COMMAND_COMMENT \".comment\"\n", info->line_nb,
				info->start + 1);
	ft_free(info);
	exit(EXIT_FAILURE);
}
