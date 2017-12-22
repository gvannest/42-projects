/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:13:36 by gvannest          #+#    #+#             */
/*   Updated: 2017/12/22 15:30:06 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percent(const char *str, int i)
{
		return (str[i + 1] == '%');
}

static void	ft_buf_test(char *buf, int i)
{
	if ((i % BUF_SIZE) == 0)
	{
		ft_putstr(buf);
		ft_bzero(buf, BUF_SIZE);
	}
}

void		ft_lecture(const char *str, char *buf, t_lst *p)
{
	while (str[p->len] != '%' && str[p->len])
	{
		ft_buf_test(buf, p->len);
		buf[p->len % BUF_SIZE] = str[(p->len)++];
	}
	if (str[p->len] == '\0')
	{
		ft_putstr(buf);
		return ;
	}
	if (ft_percent(str, p->len))
	{
		(p->nb_percent)++;
		(p->len)++;
		ft_buf_test(buf, p->len);
		buf[p->len % BUF_SIZE] = str[(p->len)++];
		return (ft_lecture(str, buf, p));
	}
}
