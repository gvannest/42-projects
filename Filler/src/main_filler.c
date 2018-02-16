/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:32:53 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/16 17:11:25 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static void		ft_reinit_filler(t_filler *game, char **line)
{
	int i;

	i = 0;
	while (PIECE[i])
		ft_strdel(&PIECE[i++]);
	ft_strdel(line)
}

int		main()
{
	t_filler	game;
	char	*line;
	int		i;

	i = 0;
	line = 0;
	ft_bzero(&game, sizeof(game));
	while (i < 3)
	{
		ft_putstr_fd("test\n", 2);
		get_next_line(0, &line);
		ft_getinfo(&game, &line);
		ft_printf("8 2\n");
		ft_reinit_filler(&game, &line);
		i++;
	}
	ft_display_fd(&game);
	close(game.fd);
	return (0);
}
