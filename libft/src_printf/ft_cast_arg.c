/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:05:09 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/10 12:45:22 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_cast_nsigned(t_lst *p, va_list ap)
{
	intmax_t n;

	if (SIZE & L || SIZE & LL || TYPE == 'D')
		n = (intmax_t)va_arg(ap, long);
	else if (SIZE & HH)
		n = (intmax_t)((char)va_arg(ap, int));
	else if (SIZE & H)
		n = (intmax_t)((short)va_arg(ap, int));
	else if (SIZE & J)
		n = va_arg(ap, intmax_t);
	else if (SIZE & Z)
		n = ft_cast_nunsigned(p, ap);
	else
		n = (intmax_t)va_arg(ap, int);
	return (n);
}

uintmax_t	ft_cast_nunsigned(t_lst *p, va_list ap)
{
	uintmax_t n;

	if (SIZE & J || TYPE == 'p' || TYPE == 'U' || TYPE == 'O')
		n = va_arg(ap, uintmax_t);
	else if (SIZE & HH)
		n = (uintmax_t)((unsigned char)va_arg(ap, unsigned int));
	else if (SIZE & H)
		n = (uintmax_t)((unsigned short)va_arg(ap, unsigned int));
	else if (SIZE & L || SIZE & LL)
		n = (uintmax_t)va_arg(ap, unsigned long);
	else if (SIZE & Z)
		n = (uintmax_t)(va_arg(ap, size_t));
	else
		n = (uintmax_t)va_arg(ap, unsigned int);
	return (n);
}

wchar_t		*ft_cast_string(t_lst *p, va_list ap)
{
	wchar_t	*string;

	if (TYPE == 'S' || ((SIZE & L) && TYPE == 's') ||
		((SIZE & LL) && TYPE == 's'))
		string = (va_arg(ap, wchar_t*));
	else
		string = (wchar_t*)(va_arg(ap, char*));
	return (string);
}

wchar_t		ft_cast_char(t_lst *p, va_list ap)
{
	(void)p;
	return ((wchar_t)(va_arg(ap, int)));
}
