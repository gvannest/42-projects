/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:48:36 by achirat           #+#    #+#             */
/*   Updated: 2017/11/17 17:55:41 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		a;
	int		len;

	a = 0;
	len = ft_strlen(s1);
	str = (char*)malloc(sizeof(*str) * len + 1);
	if (str == NULL)
		return (0);
	while (a < len)
	{
		str[a] = s1[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}
