/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:48:55 by achirat           #+#    #+#             */
/*   Updated: 2017/11/16 12:02:51 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	len;
	size_t	index;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	str = ft_strnew(len);
	if (str)
	{
		index = 0;
		while (s[index] != '\0')
		{
			str[index] = f(s[index]);
			index++;
		}
		return (str);
	}
	else
		return (0);
}
