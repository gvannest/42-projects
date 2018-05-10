/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:06:39 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/14 13:31:23 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (!(ptr = malloc(sizeof(*ptr) * size)))
		return (0);
	while (i < size)
	{
		((unsigned char*)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
