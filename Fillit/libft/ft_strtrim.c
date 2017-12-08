/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:27:54 by achirat           #+#    #+#             */
/*   Updated: 2017/11/17 18:38:23 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	j;

	if (!s)
		return (0);
	len = 0;
	j = ft_strlen(s) - 1;
	while ((s[len] == '\n' || s[len] == '\t' || s[len] == ' ') &&\
			s[len] != '\0')
		len++;
	while ((s[j] == '\n' || s[j] == '\t' || s[j] == ' ') && j > len)
		j--;
	if (!(str = ft_strsub(s, len, j - len + 1)))
		return (0);
	return (str);
}
