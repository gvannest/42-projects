/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:38:45 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/18 12:07:28 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_dtabptr.h"

static int	ft_fill_buffer(const char *format, t_lst *p, va_list ap)
{
	size_t	i;

	i = 0;
	while (format[INDEX] != '%' && format[INDEX])
	{
		(format[INDEX] == '{' ? ft_couleur(p, format) :
		ft_buffer(format[INDEX++], p));
	}
	if (!format[INDEX])
		return (0);
	if (ft_control_flags(format, p) < 0)
		return (-1);
	ft_clean_options(p);
	while (i < 16)
	{
		if (TYPE == dtabtype[i].c)
		{
			if (dtabtype[i].f_type(p, ap) < 0)
				return (-1);
		}
		i++;
	}
	ft_reinit_struct(p);
	INDEX++;
	return (0);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		m;
	t_lst	p;

	m = 0;
	if (format == NULL || fd < 1)
		return (-1);
	ft_bzero(&p, sizeof(t_lst));
	va_start(ap, format);
	while (format[p.index])
	{
		m = p.index_buf;
		if (ft_fill_buffer(format, &p, ap) < 0)
		{
			if (m % BUF_SIZE != 0)
				write(1, p.buf, m % BUF_SIZE);
			return (-1);
		}
	}
	va_end(ap);
	if (p.index_buf % BUF_SIZE != 0)
		write(fd, p.buf, p.index_buf % BUF_SIZE);
	return (p.index_buf);
}
