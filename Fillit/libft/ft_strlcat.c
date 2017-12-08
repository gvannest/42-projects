/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:21:40 by achirat           #+#    #+#             */
/*   Updated: 2017/11/15 14:14:48 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	index;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	index = 0;
	if (len_dest >= size)
		return (len_src + size);
	while (dest[index] != '\0' && index < (size - 1))
		index++;
	while (*src && index < (size - 1))
	{
		dest[index] = *src;
		index++;
		src++;
	}
	dest[index] = '\0';
	return (len_src + len_dest);
}
