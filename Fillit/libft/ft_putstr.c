/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:09:39 by achirat           #+#    #+#             */
/*   Updated: 2017/11/17 14:04:24 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *str)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (*str != '\0')
	{
		write(1, &*str, 1);
		str++;
	}
}