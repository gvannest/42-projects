/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:56:07 by achirat           #+#    #+#             */
/*   Updated: 2017/11/09 09:11:18 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	a;

	a = 0;
	while (a < len && src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	while (a < len)
	{
		dest[a] = '\0';
		a++;
	}
	return (dest);
}
