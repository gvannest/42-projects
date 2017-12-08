/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:09:41 by achirat           #+#    #+#             */
/*   Updated: 2017/11/17 16:58:12 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[b] != '\0')
	{
		a = 0;
		while (needle[a] == haystack[b + a] && needle[a] != '\0')
		{
			a++;
		}
		if (needle[a] == '\0')
			return ((char*)&haystack[b]);
		b++;
	}
	return (0);
}
