/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:27:41 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/10 15:02:23 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width(t_lst *p, char c, size_t len)
{
	int		i;
	int		j;

	i = WIDTH - PRECISION;
	j = WIDTH - len;
	while (i > 0 && j > 0)
	{
		ft_buffer(c, p);
		i--;
		j--;
	}
}

static void		ft_precision(t_lst *p, size_t len)
{
	int		i;

	i = PRECISION - len;
	while (i > 0)
	{
		ft_buffer('0', p);
		i--;
	}
}

int				ft_type_u(t_lst *p, va_list ap)
{
	uintmax_t	n;
	char		*itoa;
	size_t		len;
	size_t		i;

	i = 0;
	n = ft_cast_nunsigned(p, ap);
	itoa = ft_itoabase_u(n, "0123456789");
	len = ft_strlen(itoa);
	if (PRECISION_ON && (FLAGS & ZERO))
		FLAGS = FLAGS ^ ZERO;
	if ((!(FLAGS & ZERO) || PRECISION) && !(FLAGS & MINUS))
		ft_width(p, ' ', len);
	if (PRECISION_ON && n == 0 && PRECISION == 0)
		return (0);
	if (FLAGS & ZERO && !PRECISION_ON)
		ft_width(p, '0', len);
	ft_precision(p, len);
	while (itoa[i])
		ft_buffer(itoa[i++], p);
	if (FLAGS & MINUS)
		ft_width(p, ' ', len);
	if (itoa && n != 0)
		ft_strdel(&itoa);
	return (0);
}
