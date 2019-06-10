/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 09:59:59 by msicot            #+#    #+#             */
/*   Updated: 2017/11/17 08:52:44 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*t;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
		i += 1;
	while ((s[j] == 32 || s[j] == '\n' || s[j] == '\t') && j > i)
		j -= 1;
	if (!(t = ft_strsub(s, i, (j - i + 1))))
		return (NULL);
	return (t);
}
