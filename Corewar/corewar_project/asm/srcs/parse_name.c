/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:22:10 by msicot            #+#    #+#             */
/*   Updated: 2018/06/25 16:31:16 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_new_name(t_asm *info, char *line, int len)
{
	int	nb;
	int	i;

	nb = 0;
	i = (len > 5) ? 5: -1;
	if (i < 0)
		info->error = 1;
	while (i > 0 && i < len)
	{
		if (line[i] == '"')
			++nb;
		if (nb == 2)
			break;
		++i;
	}
	info->name_f = (nb < 2) ? -1 : 1;
	if (i != len)
	{
		info->err_pos = i + 1;
		info->error = 1;
		printf("Error ft_new_name  namei=%d len-1=%d\n", i, len-1);
	}
}

static void	ft_nline(t_asm *info, char *line, int len)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '"')
		{
			++nb;
			break;
		}
		++i;
	}
	if (nb == 1)
	{
		info->name_f = 1;
	}
	if (i != len -1)
	{
		info->err_pos = i + 1;
		info->error = 1;
		printf("Error ft_nline name\n");
	}
}

void		ft_parse_name(t_asm *info, char *line)
{
	if (info->comment_f < 0)
		info->error = 1;
	if (info->name_f == 0 && !ft_strncmp(line, NAME_CMD_STRING, 5))
	{
		ft_new_name(&(*info), line, (int)ft_strlen(line));
	}
	else if (info->name_f == -1)
	{
		ft_nline(&(*info), line, (int)ft_strlen(line));
	}
	else if (info->name_f == 1)
		info->stop = 1;
	else
		info->error = 2;
	printf("name_f = %d\n", info->name_f);
}









