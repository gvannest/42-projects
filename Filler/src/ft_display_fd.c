/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:07:57 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/16 17:10:28 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_filler.h"

void	ft_display_fd(t_filler *game)
{
	int i;
	int k;

	i = 0;
	k = 0;
	game->fd = open("/Users/gvannest/Filler/tests/test_print.txt", O_RDWR | O_CREAT, 777);
	while (BOARD[i])
	{
		ft_putstr_fd(BOARD[i++], game->fd);
		ft_putchar_fd('\n', game->fd);
	}
	ft_putnbr_fd(PIECE_NBLN, game->fd);
	ft_putchar_fd('\n', game->fd);
	ft_putnbr_fd(PIECE_NBCOL, game->fd);
	ft_putchar_fd('\n', game->fd);
	while (PIECE[k])
	{
		ft_putstr_fd(PIECE[k++], game->fd);
		ft_putchar_fd('\n', game->fd);
	}
}
