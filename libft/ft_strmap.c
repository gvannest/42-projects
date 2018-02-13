/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:07:30 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/21 09:19:13 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	if (s)
	{
		i = 0;
		if (!(str = (char*)malloc(sizeof(*str) * (ft_strlen(s) + 1))))
			return (0);
		while (*(s + i) != '\0')
		{
			str[i] = (*f)(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}
