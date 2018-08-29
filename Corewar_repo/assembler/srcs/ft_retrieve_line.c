/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retrieve_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:11:18 by msicot            #+#    #+#             */
/*   Updated: 2018/08/28 14:31:23 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	too_much(t_asm *info)
{
	++info->quote;
	if (info->comment_f == -1)
		info->comment_f = 1;
	else if (info->name_f == -1)
		info->name_f = 1;
}

void		parse_line(t_asm *info, char *line, char *target)
{
	int	i;

	i = info->start;
	while (line[i] && line[i] != '"')
	{
		if (ft_strlen(target) < ((info->comment_f == -1)
					? COMMENT_LENGTH : PROG_NAME_LENGTH))
		{
			if (line[i])
				target[ft_strlen(target)] = line[i];
		}
		else
		{
			info->error = 1;
			break ;
		}
		++i;
	}
	if (line[i] == '"')
		too_much(&(*info));
	info->end = i;
}

void		retrieve_line(t_asm *info, char *line)
{
	if (info->comment_f == -1)
	{
		parse_line(info, line, info->comment);
		if (info->comment_f == -1)
			info->comment[ft_strlen(info->comment)] = '\n';
	}
	else if (info->name_f == -1)
	{
		parse_line(info, line, info->name);
		if (info->name_f == -1)
			info->name[ft_strlen(info->name)] = '\n';
	}
	if (ft_strlen(info->comment) > (COMMENT_LENGTH))
		ft_error_length(info, 2);
	else if (ft_strlen(info->name) > (PROG_NAME_LENGTH))
		ft_error_length(info, 1);
}
