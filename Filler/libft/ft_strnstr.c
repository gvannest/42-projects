/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:33:40 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/23 12:06:16 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)hay);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] == needle[j] && (i + j) < len && needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char*)(hay + i));
		i++;
	}
	return (0);
}
