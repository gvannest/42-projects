/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:25:26 by msicot            #+#    #+#             */
/*   Updated: 2018/08/02 11:51:08 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	command_name_error(t_asm *info, char *arg)
{
	info->error = 2;
	parsing_error(info, arg);
	exit(1);
}

void	ft_error_management(t_asm *info, char *arg)
{
	if (info->lock == 1 && (info->comment_f == -1 || info->name_f == -1))
	{
		if (info->quote == 0)
		{
			info->error = (info->name_f == -1 || info->comment_f == -1) ? 4 : 2;
			parsing_error(&(*info), arg);
		}
	}
}
