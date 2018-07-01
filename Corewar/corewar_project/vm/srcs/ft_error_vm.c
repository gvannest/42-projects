/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_vm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:30:00 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/29 19:17:32 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_error_vm(char error_code, char *msg1, char *msg2, int v1)
{
	if (error_code == 0)
		ft_dprintf(2, "%s\nSource : %s\n%s\n", msg1, msg2,
				strerror(errno));
	else if (error_code == 1)
	{
		ft_dprintf(2, "%s\nUsage : ./corewar -visual [-dump nbr_cycles]", msg1);
		ft_dprintf(2, " [[-n number] champion1.cor]...\n");
		ft_dprintf(2, "Note : [number] must be different than 0\n");
	}
	else if (error_code == 2)
		ft_dprintf(2, "%s\nSource file : %s\n%#x != %#x", msg1, msg2, v1,
				COREWAR_EXEC_MAGIC);
	else if (error_code == 3)
		ft_dprintf(2, "%s\nNumber of players must be between 1 and %d\n", msg1,
				MAX_PLAYERS);
	else if (error_code == 4)
	{
		ft_dprintf(2, "%s\nFrom file : %s\n", msg1, msg2);
		if (v1 == 1)
			ft_dprintf(2, "Maximum champion's name size : %d bytes\n",
					PROG_NAME_LENGTH);
		else
			ft_dprintf(2, "Maximum comment size : %d bytes\n", COMMENT_LENGTH);
	}
	else if (error_code == 5)
		ft_dprintf(2, "%s\nFrom file : %s\n%d bytes vs. [1, %d] bytes\n",
				msg1, msg2, v1, CHAMP_MAX_SIZE);
	else if (error_code == 6)
	{
		ft_dprintf(2, "%s\nFrom file : %s\n", msg1, msg2);
		if (v1 == 1)
			ft_dprintf(2, "between name and number of instructions\n", 2);
		else
			ft_putstr_fd("between comment and instructions\n", 2);
	}
	else if (error_code == 7)
		ft_dprintf(2, 
	exit(EXIT_FAILURE);
}
