/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:55:27 by achirat           #+#    #+#             */
/*   Updated: 2017/11/13 15:34:25 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (!s1 || !s2)
		return (0);
	while (index < n && s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return (0);
		index++;
	}
	if ((s1[index] == '\0' && s2[index] == '\0') || index == n)
		return (1);
	else
		return (0);
}
