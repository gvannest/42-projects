/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:21:10 by msicot            #+#    #+#             */
/*   Updated: 2018/08/28 14:21:16 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c_tmp;

	if (str)
	{
		i = 0;
		j = ft_strlen(str) - 1;
		while (i < j)
		{
			c_tmp = str[i];
			str[i] = str[j];
			str[j] = c_tmp;
			i++;
			j--;
		}
	}
	return (str);
}
