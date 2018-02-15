/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:15:54 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/15 15:28:16 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_filler(t_filler *game)
{
	char	*line;

	line = 0;
	get_next_line(0, &line);
	while (!ft_strstr(line, "$$$"))
		get_next_line(0, &line);
	if (ft_strchr(line, '1'))
		PIECE = 'O';
	else
		PIECE = 'X';
}

/*
void	ft_filler(t_filler *game)
{
*/	
