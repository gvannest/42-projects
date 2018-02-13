/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:27:41 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/10 14:55:52 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width(t_lst *p, size_t len, intmax_t n)
{
	int		i;
	int		j;
	int		k;
	char	c;

	k = 0;
	c = ' ';
	i = WIDTH - PRECISION;
	(FLAGS & ZERO && !PRECISION_ON ? c = '0' : c);
	j = (n == 0 && PRECISION_ON && PRECISION == 0 ? WIDTH : WIDTH - len);
	if (((FLAGS & SPACE) || (FLAGS & PLUS)) && n >= 0)
		k++;
	(FLAGS & SPACE && n >= 0 ? ft_buffer(' ', p) : 1);
	if ((FLAGS & PLUS) && n >= 0 && c == '0')
		ft_buffer('+', p);
	if (n < 0)
	{
		i--;
		(c == '0' ? ft_buffer('-', p) : 1);
	}
	while (i - k > 0 && j - k > 0)
	{
		ft_buffer(c, p);
		k++;
	}
}

static void		ft_precision(t_lst *p, char *itoa, size_t len)
{
	int		i;

	i = PRECISION - len;
	if (itoa[0] == '-')
		i++;
	while (i > 0)
	{
		ft_buffer('0', p);
		i--;
	}
}

int				ft_type_di(t_lst *p, va_list ap)
{
	intmax_t	n;
	char		*itoa;
	size_t		len;
	size_t		i;

	i = 0;
	n = ft_cast_nsigned(p, ap);
	itoa = ft_itoabase_s(n, "0123456789");
	len = ft_strlen(itoa);
	if (!(FLAGS & MINUS))
		ft_width(p, len, n);
	if ((n >= 0 && (FLAGS & PLUS) && (!(FLAGS & ZERO) || PRECISION_ON)))
		ft_buffer('+', p);
	if (n < 0 && (!(FLAGS & ZERO) || PRECISION_ON))
		ft_buffer('-', p);
	if (PRECISION_ON && n == 0 && PRECISION == 0)
		return (0);
	ft_precision(p, itoa, len);
	(itoa[0] == '-' ? i = 1 : i);
	while (itoa[i])
		ft_buffer(itoa[i++], p);
	if (FLAGS & MINUS)
		ft_width(p, len, n);
	(itoa && n != 0 ? ft_strdel(&itoa) : 1);
	return (0);
}
