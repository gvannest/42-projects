/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:27:14 by achirat           #+#    #+#             */
/*   Updated: 2017/11/15 17:25:32 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t			len;
	unsigned int	index;

	if (s == NULL || !f)
		return ;
	len = ft_strlen(s);
	index = 0;
	while (index < len)
	{
		(*f)(index, &(s[index]));
		index++;
	}
}
