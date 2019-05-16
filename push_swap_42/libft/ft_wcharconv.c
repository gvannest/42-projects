/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:54:53 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/10 15:02:46 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_unicode4(wchar_t c, char str[5])
{
	str[0] = (c >> 18) | 0xf0;
	str[1] = ((c >> 12) & 0x3f) | 0x80;
	str[2] = ((c >> 6) & 0x3f) | 0x80;
	str[3] = (c & 0x3f) | 0x80;
}

static void		ft_unicode3(wchar_t c, char str[5])
{
	str[0] = (c >> 12) | 0xe0;
	str[1] = ((c >> 6) & 0x3f) | 0x80;
	str[2] = (c & 0x3f) | 0x80;
}

static void		ft_unicode2(wchar_t c, char str[5])
{
	str[0] = (c >> 6) | 0xc0;
	str[1] = (c & 0x3f) | 0x80;
}

int				ft_wcharconv(wchar_t c, char str[5])
{
	char	a;

	a = 0;
	if (c > 0x10ffff || (c >= 0xd800 && c <= 0xdfff) || c < 0)
		return (-1);
	while (c >> a)
		a++;
	if ((MB_CUR_MAX == 1 && a > 8) || (MB_CUR_MAX == 2 && a > 11) ||
		(MB_CUR_MAX == 3 && a > 16) || (MB_CUR_MAX == 4 && a > 21))
		return (-1);
	if (a <= 8)
		str[0] = c;
	else if (a > 8 && a <= 11)
		ft_unicode2(c, str);
	else if (a > 11 && a <= 16)
		ft_unicode3(c, str);
	else if (a > 16 && a <= 21)
		ft_unicode4(c, str);
	return (0);
}
