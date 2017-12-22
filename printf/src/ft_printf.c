/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:38:45 by gvannest          #+#    #+#             */
/*   Updated: 2017/12/22 17:16:33 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	char	buf[BUF_SIZE];
	t_lst	*p;

	if (!(p = (t_lst*)malloc(sizeof(*p))))
		return (-1);
	ft_bzero(p, sizeof(*p));
	ft_lecture(format, buf, p);
	if (format[p->len])
	{

	return (p->len - p->nb_percent);
}

	
