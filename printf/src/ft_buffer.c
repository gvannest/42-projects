/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:13:36 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/11 10:02:40 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_buf_test(char *buf, int i)
{
	if ((i % BUF_SIZE) == 0)
	{
		ft_putstr(buf);
		ft_bzero(buf, BUF_SIZE);
	}
}

void		ft_buffer(const char *str, char *buf, t_lst *p)
{
	while (str[INDEX] != '%' && str[INDEX])
	{
		ft_buf_test(buf, INDEX_BUF);
		buf[INDEX_BUF % BUF_SIZE] = str[INDEX];
		INDEX++;
		INDEX_BUF++;
	}
	return ;
}
