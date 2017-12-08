/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:02:18 by achirat           #+#    #+#             */
/*   Updated: 2017/11/10 10:42:59 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;
	char		b;

	len = ft_strlen(s);
	b = (char)c;
	while (b != s[len] && len)
		len--;
	if (s[len] != b)
		return (0);
	return ((char*)(s + len));
}
