/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:54:26 by msicot            #+#    #+#             */
/*   Updated: 2018/06/28 13:23:19 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_check_data(t_asm *info)
{
	//check comment name
	if ((info->name_f != 1 || info->comment_f != 1))
	{
		info->error = 1;
		info->err_pos = 1;
	}

}

static void	check_line(t_asm *info, char *line, int len)
{
	int i;
	
	i = len;
	if (line == NULL)
		return ;
	line = ft_strtrim(line);
	if (info->comment_f <= 0 || info->name_f <= 0)
		ft_parse_cmd(&(*info), line);
	ft_strdel(&line);
}

void		ft_gnl(t_asm *info)
{
	char	*line;

	line = 0;
	while ((info->gnl = get_next_line(info->fp, &line)) > 0 && info->error == 0
			&& info->stop == 0)
	{
			++info->line_nb;
//			printf("%s\n", line);
			check_line(&(*info), line, ft_strlen(line));
			if (info->error != -1)
				parsing_error(info, line);
			ft_strdel(&line);
	}
	ft_check_data(&(*info));
	free(line);
	printf("Name =%s\nComment=%s\n", info->name, info->comment);
}
