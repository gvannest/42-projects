/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:05:30 by achirat           #+#    #+#             */
/*   Updated: 2017/11/16 13:35:03 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	*mem;
	size_t	fill;

	fill = 0;
	mem = (size_t*)malloc(sizeof(*mem) * size);
	if (mem == NULL)
		return (0);
	while (fill < size)
	{
		mem[fill] = 0;
		fill++;
	}
	return ((void*)mem);
}
