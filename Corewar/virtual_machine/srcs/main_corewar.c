/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:54:27 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/15 18:29:18 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		ft_open_cor(t_arena *arena, char **argv, int i)
{
	int		fd;
	char	line[2192];
	int		ret;

	(void)arena;
	if ((fd = open(argv[i], O_RDONLY)) < 0)
		return (-1);
	if ((ret = read(fd, line, 2192)) < 0)
		return (-1);

	while (get_next_line(fd, &line) < 0)
		return (-1);
	if (close(fd) < 0)
		return (-1);
	ft_print_test(line);
	//ft_parse(line, arena);
	return (0);
}

int				ft_fill_arena(


int				main(int argc, char **argv)
{
	t_arena	arena;

	if (argc == 3)
	{
		ft_open_cor(&arena, argv, 1);
		ft_open_cor(&arena, argv, 2);
		ft_fill_arena(&arena);
	}
	return (0);
}

