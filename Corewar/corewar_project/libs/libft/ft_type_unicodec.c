/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_unicodec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 11:31:06 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/10 12:41:23 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width(t_lst *p, char n)
{
	int		i;
	char	t;

	t = ' ';
	(FLAGS & ZERO ? t = '0' : t);
	i = WIDTH - n;
	while (i > 0)
	{
		ft_buffer(t, p);
		i--;
	}
}

int				ft_type_unicodec(t_lst *p, va_list ap)
{
	wchar_t		c;
	char		str[5];
	int			i;
	int			len;

	i = 0;
	ft_bzero(str, 5);
	c = ft_cast_char(p, ap);
	if (ft_wcharconv(c, str) < 0)
		return (-1);
	len = ft_strlen(str);
	if (!(FLAGS & MINUS))
		ft_width(p, len);
	if (c == 0)
		ft_buffer(0, p);
	while (i < len)
		ft_buffer((const char)str[i++], p);
	if (FLAGS & MINUS)
		ft_width(p, len);
	return (0);
}
