/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 08:40:27 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/21 11:40:49 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s)
	{
		i = 0;
		k = 0;
		j = ft_strlen(s) - 1;
		while ((s[i] == ' ' || s[i] == ',' || s[i] == '\n' ||
				s[i] == '\t') && s[i])
			i++;
		while ((s[j] == ' ' || s[j] == ',' || s[j] == '\n' ||
				s[j] == '\t') && j)
			j--;
		if (j <= i)
			str = ft_strnew(1);
		else
			str = ft_strsub(s, i, j - i + 1);
		return (str);
	}
	return (0);
}
