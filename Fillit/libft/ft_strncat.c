/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:55:44 by achirat           #+#    #+#             */
/*   Updated: 2017/11/17 15:45:37 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	a;

	a = 0;
	if (n == 0)
		return (dest);
	len = ft_strlen(dest);
	while (a < n && src[a] != '\0')
	{
		dest[len] = src[a];
		len++;
		a++;
	}
	dest[len] = '\0';
	return (dest);
}
