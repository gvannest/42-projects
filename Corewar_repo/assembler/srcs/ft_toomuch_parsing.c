/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toomuch_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:36:47 by msicot            #+#    #+#             */
/*   Updated: 2018/08/28 14:40:12 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_toomuch_parsing(t_asm *info, char *line, int i)
{
	int	found;

	found = 0;
	while (line[i])
	{
		if (line[i] == '"')
			found++;
		i++;
	}
	if (found == 1)
		info->comment[0] = '\n';
}
