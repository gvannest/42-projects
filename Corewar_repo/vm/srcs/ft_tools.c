/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:02:34 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 09:10:52 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned long	ft_read_memory(char *map, int start, size_t k)
{
	unsigned short		i;
	unsigned long long	res;

	i = 0;
	res = 0;
	while (i < k)
	{
		res = res | (map[(start + i) % MEM_SIZE] & 0xff) << 8 * (k - 1 - i);
		i++;
	}
	return (res);
}

void			ft_write_memory(char *map, unsigned int v, int start, size_t k)
{
	unsigned short		i;

	i = 0;
	while (i < k)
	{
		map[(start + i) % MEM_SIZE] = v >> (8 * (k - 1 - i));
		i++;
	}
}
