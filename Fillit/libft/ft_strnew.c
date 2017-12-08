/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:11:30 by achirat           #+#    #+#             */
/*   Updated: 2017/11/16 11:48:20 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	a;

	a = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	while (a < size)
	{
		str[a] = '\0';
		a++;
	}
	str[a] = '\0';
	return (str);
}
