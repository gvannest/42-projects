/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:42:09 by achirat           #+#    #+#             */
/*   Updated: 2017/11/13 11:53:59 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t len;
	size_t index;

	index = 0;
	if (s == NULL)
		return ;
	len = ft_strlen(s);
	while (index < len)
	{
		s[index] = '\0';
		index++;
	}
}
