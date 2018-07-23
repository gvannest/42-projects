/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:27:41 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/14 10:28:37 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width(t_lst *p)
{
	int		i;
	char	t;

	t = ' ';
	i = WIDTH - 1;
	(FLAGS & ZERO ? t = '0' : t);
	while (i > 0)
	{
		ft_buffer(t, p);
		i--;
	}
}

int				ft_type_c(t_lst *p, va_list ap)
{
	wchar_t		c;

	if (SIZE & L || SIZE & LL)
		return (ft_type_unicodec(p, ap));
	c = (char)ft_cast_char(p, ap);
	if (!(FLAGS & MINUS))
		ft_width(p);
	ft_buffer(c, p);
	if (FLAGS & MINUS)
		ft_width(p);
	return (0);
}
