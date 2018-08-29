/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:54:26 by msicot            #+#    #+#             */
/*   Updated: 2018/08/28 14:28:34 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	reset_flags(t_asm *info)
{
	info->lock = 0;
	info->start = 0;
	info->end = 0;
	info->comchr_f = 0;
	info->comma_f = 0;
	info->operator_f = 0;
	info->label_f = 0;
	info->comchr_f = 0;
	info->directchr_f = 0;
	info->nb_comma = 0;
	info->nb_param = 0;
	info->addon = info->line_nb;
	ft_strdel(&info->err_log);
}

static void	ft_check_data(t_asm *info)
{
	if (info->name_f == -1 || info->comment_f == -1)
	{
		info->error = 5;
		parsing_error(info, NULL);
	}
	if (info->line_nb == 0)
	{
		info->error = 5;
		info->line_nb = 1;
		parsing_error(info, NULL);
	}
}

static void	check_line(t_asm *info, char *line)
{
	if (line == NULL)
		return ;
	reset_flags(&(*info));
	parse_correctly(&(*info), line);
}

void		ft_gnl(t_asm *info)
{
	char	*line;

	line = 0;
	while ((info->gnl = get_next_line(info->fp, &line)) > 0 && info->error == 0
			&& info->stop == 0)
	{
		++info->line_nb;
		check_line(&(*info), line);
		if (info->error != 0)
			parsing_error(info, line);
		ft_strdel(&line);
	}
	ft_check_data(&(*info));
	free(line);
}
