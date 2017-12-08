/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:47:03 by achirat           #+#    #+#             */
/*   Updated: 2017/11/17 15:51:54 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				a;
	unsigned char		c2;
	unsigned char		*dst2;
	const unsigned char	*src2;

	c2 = c;
	dst2 = dst;
	src2 = src;
	a = 0;
	while (a < n)
	{
		dst2[a] = src2[a];
		if (c2 == src2[a])
			return (&dst2[a + 1]);
		a++;
	}
	return (0);
}
