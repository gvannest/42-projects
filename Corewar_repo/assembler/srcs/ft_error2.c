/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:23:25 by msicot            #+#    #+#             */
/*   Updated: 2018/08/29 12:27:00 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_instr(t_asm *info, char *arg)
{
	if (ft_strequ(arg, ".name"))
	{
		ft_dprintf(2, "Syntax error at token [TOKEN][%03d:%03d]	COMMAND_NAME\
				\"%s\"\n", info->line_nb, info->start + 1, info->err_log);
	}
	else if (ft_strequ(arg, ".comment"))
	{
		ft_dprintf(2, "Syntax error at token [TOKEN][%03d:%03d] \
				COMMAND_COMMENT \"%s\"\n", info->line_nb, info->start + 1,
				info->err_log);
	}
	else
		ft_dprintf(2, "Syntax error at token [TOKEN][%03d:%03d] INSTRUCTION \
				\"%s\"\n", info->line_nb, info->start + 1, info->err_log);
}
