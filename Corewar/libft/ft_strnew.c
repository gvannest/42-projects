/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:52:23 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/14 14:33:54 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!(ptr = (char*)malloc(sizeof(*ptr) * (size + 1))))
		return (0);
	while (i <= size)
	{
		*(ptr + i) = '\0';
		i++;
	}
	return (ptr);
}
