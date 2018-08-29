/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:22:39 by srossi            #+#    #+#             */
/*   Updated: 2018/08/01 19:14:29 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_find_index_arg(char *arg)
{
	int index;

	index = 0;
	while (index < 17)
	{
		if (ft_strequ(arg, g_op_tab[index].name))
			break ;
		index++;
	}
	return (index);
}
