/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:54:20 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/21 16:48:27 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	c1 = (unsigned char)c;
	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			dst1[i] = src1[i];
			if (src1[i] == c1)
				return ((void*)(dst1 + i + 1));
			i++;
		}
		return (0);
	}
	return (0);
}
