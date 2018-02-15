/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:32:53 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/15 15:23:32 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		main()
{
	t_filler	game;

	ft_bzero(&game, sizeof(game));
	ft_filler(&game);
	ft_display_fd(&game);
	return (0);
}
