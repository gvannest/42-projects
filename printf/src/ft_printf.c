/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:38:45 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/11 15:48:39 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	char	buf[BUF_SIZE];
	t_lst	p;
	va_list	ap;

	ft_init_struct(&p);
	ft_bzero(buf, BUF_SIZE);
	va_start(ap, format);
	ft_buffer(format, buf, &p);
	if (!format[p.index])
		return (p.index);
	if (ft_control_flags(format, &p) < 0 || ft_clean_flags(&p) < 0)
	{
		ft_error(&p);
		return (-1);
	}
	p.param = va_arg(ap, void*);
	va_end(ap);
	if (buf[0] != '\0')
		ft_putstr(buf);
	return (0);
}

	
