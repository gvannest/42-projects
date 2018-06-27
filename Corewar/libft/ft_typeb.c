/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:27:41 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/10 16:26:02 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width(t_lst *p, size_t len, uintmax_t n)
{
	int		i;
	int		j;
	int		k;
	char	c;

	c = ' ';
	i = WIDTH - PRECISION;
	j = (n == 0 && PRECISION_ON ? WIDTH : WIDTH - len);
	k = 0;
	(FLAGS & ZERO && !PRECISION_ON ? c = '0' : c);
	((FLAGS & HASH) && n > 0 ? k = 1 : k);
	while (i - k > 0 && j - k > 0)
	{
		ft_buffer(c, p);
		i--;
		j--;
	}
}

static void		ft_precision(t_lst *p, size_t len, uintmax_t n)
{
	int		i;
	int		k;

	i = PRECISION - len;
	k = 0;
	((FLAGS & HASH) && n > 0 ? k = 1 : k);
	while (i - k > 0)
	{
		ft_buffer('0', p);
		i--;
	}
}

int				ft_type_b(t_lst *p, va_list ap)
{
	uintmax_t	n;
	char		*itoa;
	size_t		len;
	size_t		i;

	i = 0;
	n = ft_cast_nunsigned(p, ap);
	itoa = ft_itoabase_u(n, "01");
	len = ft_strlen(itoa);
	if (PRECISION_ON && (FLAGS & ZERO))
		FLAGS = FLAGS ^ ZERO;
	if (!(FLAGS & MINUS))
		ft_width(p, len, n);
	if (PRECISION_ON && n == 0 && PRECISION == 0 && !(FLAGS & HASH))
		return (0);
	ft_precision(p, len, n);
	while (itoa[i])
		ft_buffer(itoa[i++], p);
	if (FLAGS & MINUS)
		ft_width(p, len, n);
	if (itoa && n != 0)
		ft_strdel(&itoa);
	return (0);
}
