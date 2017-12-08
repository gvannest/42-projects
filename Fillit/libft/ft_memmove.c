/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:31:41 by achirat           #+#    #+#             */
/*   Updated: 2017/11/16 14:54:21 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				a;
	const unsigned char *src2;
	unsigned char		*dst2;

	src2 = (const unsigned char*)src;
	dst2 = (unsigned char*)dst;
	a = 0;
	if (dst > src)
	{
		a = len - 1;
		while (len)
		{
			dst2[a] = src2[a];
			len--;
			a--;
		}
	}
	else
		while (a < len)
		{
			dst2[a] = src2[a];
			a++;
		}
	return ((void *)dst2);
}
