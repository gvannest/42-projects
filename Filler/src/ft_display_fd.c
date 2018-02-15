/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:10:36 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/15 15:20:26 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_filler.h"

void	ft_display_fd(t_filler *game)
{
	int fd;
	//char *line;

	fd = open("/Users/gvannest/Filler/tests/test_print.txt", O_RDWR, 777);
	dprintf(fd, "ok il ouve\n");
	ft_putchar_fd(PIECE, fd);
	write(fd, &PIECE, 1);
	ft_putchar_fd('\0', fd);
	close(fd);
}
