/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_separator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:26:54 by msicot            #+#    #+#             */
/*   Updated: 2018/08/02 16:03:45 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#define START line[info->start]

static void	comma_analyser(t_asm *info, char *line)
{
	if (info->comma_f == 1 || (info->nb_comma > info->nb_param) ||\
			info->operator_f == 0 || info->nb_param == 0)
	{
		info->error = 3;
		parsing_error(info, ft_strdup(","));
	}
	else if (info->end + 1 == (int)ft_strlen(line))
	{
		info->error = 4;
		parsing_error(info, ft_strdup(","));
	}
	else
	{
		info->comma_f = 1;
		++info->nb_comma;
	}
}

static void	quote_analyser(t_asm *info)
{
	if (info->quote == 0 && info->comment_f != -1 && info->name_f != -1)
		info->error = 1;
	else
	{
		if (info->quote == 0)
		{
			++info->quote;
			info->lock = 0;
		}
		else if (info->quote == 2)
		{
			info->lock = 1;
			info->quote = 0;
		}
	}
}

void		analyse_separator(t_asm *info, char *line)
{
	if (line == NULL)
		return ;
	if (START == SEPARATOR_CHAR)
		comma_analyser(info, line);
	else if (START == '"')
		quote_analyser(info);
	info->end = info->start + 1;
}
