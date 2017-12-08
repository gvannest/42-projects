/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:06:29 by achirat           #+#    #+#             */
/*   Updated: 2017/11/20 10:12:04 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_foreach(void *content, size_t len, void (*f)(void *))
{
	size_t	a;

	a = 0;
	if (!content)
		return ;
	while (a < len)
	{
		(*f)(&content[a]);
		a++;
	}
}
