/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:20:41 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/21 17:01:46 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (p1[i] == p2[i] && i < (n - 1) && p1[i] && p2[i])
		i++;
	return (p1[i] - p2[i]);
}
