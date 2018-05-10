/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:18:35 by srossi            #+#    #+#             */
/*   Updated: 2018/04/27 17:29:07 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_error.h"

int	ft_error(char *reason)
{
	int i;

	i = 0;
	while (ft_strcmp(reason, tab_errors[i].reason) != 0)
		i++;
	ft_putendl(tab_errors[i].str_print);
	return (tab_errors[i].type_error);
}

int	ft_last_check(t_game *game)
{
	if (!(game->f_start == 2 && game->f_end == 2))
	{
		if (game->f_start < 2)
			return (ft_error("no_start"));
		else
			return (ft_error("no_end"));
	}
	else if (game->room_start->next_map == NULL ||
			game->room_end->next_map == NULL)
	{
		if (game->room_start->next_map == NULL)
			return (ft_error("start_unlinked"));
		else
			return (ft_error("end_unlinked"));
	}
	return (0);
}
