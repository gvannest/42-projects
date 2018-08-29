/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_correctly.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:59:05 by msicot            #+#    #+#             */
/*   Updated: 2018/08/28 14:37:59 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_word(t_asm *info, char *arg)
{
	if (info->comment_f == 1 || info->name_f == 1)
	{
		if (info->name_f == 1 && ft_strequ(arg, ".name"))
			ft_error_doubles(info, 1);
		else if (info->comment_f == 1 && ft_strequ(arg, ".comment"))
			ft_error_doubles(info, 2);
	}
	if (info->lock == 1)
	{
		info->error = 2;
		parsing_error(info, arg);
	}
	else if (info->comment_f == 0 || info->name_f == 0)
	{
		if (ft_strequ(arg, ".name"))
			info->name_f = -1;
		else if (ft_strequ(arg, ".comment"))
			info->comment_f = -1;
		else
			command_name_error(info, arg);
		info->lock = 1;
	}
	else if (arg != NULL)
		ft_token_add(info, arg);
}

char		*retrieve_word(t_asm *info, char *line)
{
	char	*arg;
	int		i;

	i = info->start;
	while (line[i] && (ft_strchr(LABEL_CHARS, line[i]) || ft_is_nonsep(line[i],
					info->comma_f)))
	{
		i++;
	}
	info->end = i;
	if (i >= info->start)
	{
		arg = ft_strsub(line, info->start, i - info->start);
		info->err_log = ft_strdup(arg);
	}
	else
		return (ft_strnew(0));
	return (arg);
}

static int	ft_parse_it(t_asm *info, char *line)
{
	char	*arg;
	int		i;

	i = 0;
	if (info->quote == 1)
		retrieve_line(&(*info), line);
	else if (line[info->start] == '"' || ft_is_sep(line[info->start]))
		analyse_separator(info, line);
	else if (!ft_is_comchar(&info->comchr_f, line[info->start]))
	{
		arg = retrieve_word(&(*info), line);
		check_word(info, arg);
		if (info->comment_f == -1 && line[ft_strlen(line) - 1] == '"'
		&& line[0] == '.' && line[1] == 'c')
		{
			ft_toomuch_parsing(&(*info), line, i);
		}
		ft_strdel(&arg);
		ft_strdel(&info->err_log);
	}
	return (info->end);
}

int			ft_unauth_char(char c)
{
	if (ft_is_sep(c) || ft_strchr(LABEL_CHARS, c) || ft_is_othchr(c)
			|| ft_is_nonsep(c, 0) || (c == '\0'))
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void		parse_correctly(t_asm *info, char *line)
{
	int	i;

	i = 0;
	if (line != NULL && info->quote == 1 && line[0] == '\0')
		retrieve_line(&(*info), line);
	while (line[i] != '\0' && info->error == 0 && info->stop == 0)
	{
		if (ft_is_space(line[i]) && info->quote != 1)
			i++;
		else
		{
			info->start = i;
			i = ft_parse_it(&(*info), line);
		}
		if (info->comchr_f == 1)
			break ;
		if (!ft_unauth_char(line[i]))
			info->error = 6;
	}
	ft_error_management(info, line);
}
