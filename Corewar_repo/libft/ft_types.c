/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:27:41 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/12 17:13:28 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width(t_lst *p, size_t len)
{
	int		i;
	char	c;

	c = ' ';
	(FLAGS & ZERO ? c = '0' : c);
	i = WIDTH - len;
	if (PRECISION_ON)
		(PRECISION < len ? i = WIDTH - PRECISION : i);
	while (i > 0)
	{
		ft_buffer(c, p);
		i--;
	}
}

int				ft_type_s(t_lst *p, va_list ap)
{
	char		*s;
	size_t		len;
	size_t		i;

	i = 0;
	if (SIZE & L || SIZE & LL)
		return (ft_type_unicodes(p, ap));
	s = (char*)ft_cast_string(p, ap);
	if (!s)
		s = "(null)";
	len = ft_strlen((const char*)s);
	if (!(FLAGS & MINUS))
		ft_width(p, len);
	if (PRECISION_ON)
		while (s[i] && i < PRECISION)
			ft_buffer(s[i++], p);
	else
		while (s[i])
			ft_buffer(s[i++], p);
	if (FLAGS & MINUS)
		ft_width(p, len);
	return (0);
}
