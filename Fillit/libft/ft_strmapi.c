/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:22:50 by achirat           #+#    #+#             */
/*   Updated: 2017/11/16 14:14:11 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	index;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	index = 0;
	str = ft_strnew(len);
	if (str)
	{
		while (s[index])
		{
			str[index] = (*f)(index, s[index]);
			index++;
		}
		str[index] = '\0';
		return (str);
	}
	else
		return (0);
}
