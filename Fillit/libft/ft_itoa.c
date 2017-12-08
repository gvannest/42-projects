/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:44:27 by achirat           #+#    #+#             */
/*   Updated: 2017/11/16 09:26:18 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fill(char **str, int n, int len)
{
	long	n2;

	n2 = n;
	if (n >= 0)
		while (len >= 0)
		{
			(*str)[len] = n2 % 10 + 48;
			n2 = n2 / 10;
			len--;
		}
	else
	{
		n2 = -n2;
		while (len > 0)
		{
			(*str)[len] = n2 % 10 + 48;
			n2 = n2 / 10;
			len--;
		}
		(*str)[len] = '-';
	}
}

char			*ft_itoa(int n)
{
	int		len;
	long	n1;
	char	*str;

	len = 0;
	n1 = n;
	if (n1 < 0)
	{
		n1 = -n1;
		len++;
	}
	while (n1 > 9)
	{
		n1 = n1 / 10;
		len++;
	}
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (0);
	ft_fill(&str, n, len);
	return (str);
}
