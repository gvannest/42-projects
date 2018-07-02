/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 13:07:37 by msicot            #+#    #+#             */
/*   Updated: 2018/06/28 13:28:17 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
 **Comment
*/

void	ft_comment2(t_asm *info, char *line, int i)
{
	int	nb;

	if (info->quote == 1 && line[i] != '"')
	{
		nb = ft_strlen(info->comment);
		if (nb + 1 < COMMENT_LENGTH)
			info->comment[nb] = line[i];
		else
			info->stop = 1;
	}
}

void	ft_comment(t_asm *info, char *line)
{
	int i;

	i = -1;
	if (!line)
		return ;
	while (line[++i] && info->stop == 0)
	{
		ft_comment2(&(*info), line, i);
		if (info->stop == 1)
			break ;
		if (line[i] == '"')
		{
			++info->quote;
			info->comment_f = (info->quote == 2) ? 1 : -1;
			if (info->quote == 2)
				break ;
		}
	}
	if (info->quote == 2 && line[i] != '\0' && line[i + 1] != '\0')
		ft_syntax_err(&(*info), i, &line[i]);
}

/*
 **Name
*/

void	ft_name2(t_asm *info, char *line, int i)
{
	int	nb;

	if (info->quote == 1)
	{
		nb = ft_strlen(info->name);
		if (nb + 1 < PROG_NAME_LENGTH)
			info->name[nb] = line[i];
		else
			info->stop = 1;
	}
}

void	ft_name(t_asm *info, char *line)
{
	int i;

	i = -1;
	if (!line || line[0] == '\0')
		return ;
	while (line[++i] && info->stop == 0)
	{
		if (line[i] != '"')
			ft_name2(&(*info), line, i);
		if (line[i] == '"')
		{
			++info->quote;
			info->name_f = (info->quote == 2) ? 1 : -1;
			if (info->quote == 2)
				break ;
		}
	}
	if (info->quote == 2 && line[i] != '\0' && line[i + 1] != '\0')
		ft_syntax_err(&(*info), i, &line[i + 1]);
}

void	ft_parse_cmd(t_asm *info, char *line)
{
	if ((info->name_f != -1) && ((ft_strnequ(line, COMMENT_CMD_STRING, 8)
					&& info->comment_f == 0) || info->comment_f < 0))
	{
		info->quote = (info->comment_f == 0) ? 0 : info->quote;
		ft_comment(&(*info), line);
		if (info->comment_f < 0 && info->quote != 2)
			info->comment[ft_strlen(info->comment)] = '\n';
	}
	else if ((info->comment_f != -1) && ((ft_strnequ(line, NAME_CMD_STRING, 5)
					&& info->name_f == 0) || info->name_f < 0))
	{
		info->quote = (info->name_f == 0) ? 0 : info->quote;
		ft_name(&(*info), line);
		if (info->name_f < 0 && info->quote != 2 && ft_strlen(line) != 0)
		{
			info->name[ft_strlen(info->name)] = '\n';
		}
	}
}
