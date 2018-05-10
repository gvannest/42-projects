/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:15:53 by gvannest          #+#    #+#             */
/*   Updated: 2017/12/11 14:31:22 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*cpy;
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < n)
		i++;
	if (!(cpy = (char*)malloc(sizeof(*cpy) * (i + 1))))
		return (0);
	i = 0;
	while (s[i] != '\0' && i < n)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
