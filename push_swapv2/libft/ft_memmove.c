/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:37:43 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/16 14:59:07 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	i = 0;
	if (dst1 < src1)
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	else
	{
		i = len - 1;
		while (len)
		{
			dst1[i] = src1[i];
			i--;
			len--;
		}
	}
	return ((void*)dst1);
}
