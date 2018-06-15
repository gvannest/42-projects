/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:27:41 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/10 15:28:32 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flag_hash(t_lst *p)
{
	ft_buffer('0', p);
	if (TYPE == 'x')
		ft_buffer('x', p);
	else if (TYPE == 'X')
		ft_buffer('X', p);
}

static char		*ft_base(t_lst *p, uintmax_t n)
{
	char	*itoa;

	itoa = 0;
	if (TYPE == 'x')
		itoa = ft_itoabase_u(n, "0123456789abcdef");
	else if (TYPE == 'X')
		itoa = ft_itoabase_u(n, "0123456789ABCDEF");
	return (itoa);
}

static void		ft_width(t_lst *p, char c, size_t len, uintmax_t n)
{
	int		i;
	int		j;
	int		k;

	i = WIDTH - PRECISION;
	j = (n == 0 && PRECISION_ON ? WIDTH : WIDTH - len);
	k = 0;
	(FLAGS & HASH && n > 0 ? k = 2 : k);
	while (i - k > 0 && j - k > 0)
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

int				ft_type_x(t_lst *p, va_list ap)
{
	uintmax_t	n;
	char		*itoa;
	size_t		len;
	size_t		i;

	i = 0;
	n = ft_cast_nunsigned(p, ap);
	itoa = ft_base(p, n);
	len = ft_strlen(itoa);
	if ((!(FLAGS & ZERO) || PRECISION_ON) && !(FLAGS & MINUS))
		ft_width(p, ' ', len, n);
	if (PRECISION_ON && n == 0 && PRECISION == 0)
		return (0);
	if (FLAGS & HASH && n > 0)
		ft_flag_hash(p);
	if (FLAGS & ZERO && !PRECISION_ON)
		ft_width(p, '0', len, n);
	ft_precision(p, len);
	while (itoa[i])
		ft_buffer(itoa[i++], p);
	if (FLAGS & MINUS)
		ft_width(p, ' ', len, n);
	if (itoa && n != 0)
		ft_strdel(&itoa);
	return (0);
}
