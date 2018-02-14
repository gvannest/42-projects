/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:27:41 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/10 13:45:45 by gvannest         ###   ########.fr       */
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

static int		ft_strlen_unicode(wchar_t c)
{
	int	i;
	int nb_bits;
	int len;

	i = 0;
	len = 0;
	nb_bits = 0;
	while (c >> nb_bits)
		nb_bits++;
	if (nb_bits <= 8)
		len = 1;
	else if (nb_bits > 8 && nb_bits <= 11)
		len = 2;
	else if (nb_bits > 11 && nb_bits <= 16)
		len = 3;
	else if (nb_bits > 16 && nb_bits <= 21)
		len = 4;
	i++;
	return (len);
}

static int		ft_buffer_prec(t_lst *p, wchar_t *s, char str[5], size_t *m)
{
	size_t		i;
	size_t		k;
	size_t		a;

	a = 0;
	i = 0;
	while (*(s + i) && a < PRECISION)
	{
		k = 0;
		ft_bzero(str, 5);
		if (ft_wcharconv(*(s + i), str) < 0)
			return (-1);
		*m = a;
		a = a + ft_strlen_unicode(s[i++]);
		while (str[k] && a <= PRECISION)
			ft_buffer(str[k++], p);
	}
	return (0);
}

static int		ft_envoi_buffer(t_lst *p, wchar_t *s, size_t *m)
{
	char		str[5];
	size_t		i;
	size_t		k;

	i = 0;
	if (PRECISION_ON)
	{
		if (ft_buffer_prec(p, s, str, m) < 0)
			return (-1);
	}
	else
		while (*(s + i))
		{
			k = 0;
			ft_bzero(str, 5);
			if (ft_wcharconv(*(s + i++), str))
				return (-1);
			while (str[k])
				ft_buffer(str[k++], p);
		}
	return (0);
}

int				ft_type_unicodes(t_lst *p, va_list ap)
{
	wchar_t		*s;
	size_t		len;
	size_t		i;
	size_t		m;

	len = 0;
	i = 0;
	s = ft_cast_string(p, ap);
	if (!s)
		s = L"(null)";
	while (*(s + i))
		len = len + ft_strlen_unicode(s[i++]);
	if (!(FLAGS & MINUS))
		ft_width(p, len);
	if (ft_envoi_buffer(p, s, &m) < 0)
		return (-1);
	if (FLAGS & MINUS)
	{
		(PRECISION_ON && len > m ? len = m : len);
		ft_width(p, len);
	}
	return (0);
}
