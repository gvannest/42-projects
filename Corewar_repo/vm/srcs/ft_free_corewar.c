/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_corewar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:26:52 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 08:51:16 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_free_listproc(t_proc *begin_list)
{
	t_proc *tmp;

	while (begin_list)
	{
		tmp = begin_list->next;
		free(begin_list);
		begin_list = tmp;
	}
}
