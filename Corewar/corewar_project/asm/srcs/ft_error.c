/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:47:09 by msicot            #+#    #+#             */
/*   Updated: 2018/06/28 13:21:53 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_syntax_err(t_asm *info, int i, char *line)
{
	int pos;
	int	j;

	j = 0;
	pos = -1;
//	printf("i=%d pos = %d line[i] = %c\n", i,  pos, line[i]);
	while (line[pos])
	{
		if (line[pos] != ' ' && line[pos] != '"')
		{
			if (info->err_pos == -1)
			{
		//		printf("i=%d pos = %d line[pos] = %c\n", i,  pos, line[pos]);
				info->err_pos = i + pos + 2;
				info->error = 1;
			}
			while (line[pos] != ' ')
			{
				info->err_content[j] = line[pos];
				++j;
				++pos;
			}
			if (line[pos] == ' ')
				break ;
		}
		++pos;
	}
}

void	parsing_error(t_asm *info, char *line)
{
	if (info->error == 1)
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] \"%s\"\n", info->line_nb, info->err_pos, info->err_content);
	}
	else if (info->error == 1 && line == NULL)
	{
		ft_printf("2 Syntax error at token [TOKEN][%03d:%03d]\n", info->line_nb + 1, 1);
	}

}

void	ft_error(int a)
{
	if (a == 1)
	{
		perror("Error");
		//		exit(0);
	}
	else
		return ;
}
