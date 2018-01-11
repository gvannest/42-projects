/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:00:37 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/10 20:33:17 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_option(char c, char *option)
{
	size_t i;

	i = 0;
	while (option[i])
	{
		if (c == option[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_search_type(const char *str, t_lst *p)
{
	size_t	j;

	j = 0;
	while (ALL_TYPES[j])
	{
		if (ft_strchr(str, ALL_TYPES[j]))
		{
			TYPE = ALL_TYPES[j];
			return (1);
		}
		j++;
	}
	return (0);
}

static	int	ft_point(const char *format, t_lst *p, int i)
{
	PRECISION = ft_atoi(&format[++i]);
	while (format[i] && ft_isdigit(format[i]))
		i++;
	i--;
	return (i);
}

int			ft_control_flags(const char *format, t_lst *p)
{
	size_t i;

	i = ++INDEX;
	if (!ft_search_type((format + i), p))
		return (-1);
	while (format[i] && ft_check_option(format[i], ALL_FLAGS))
		i++;
	if (!(FLAGS = ft_strsub(format, INDEX, i - INDEX)))
		exit(EXIT_FAILURE);
	WIDTH = ft_atoi(format + i);
	while (format[i] && ft_isdigit(format[i]))
		i++;
	if (format[i] == '.')
		i = ft_point(format, p, i);
	INDEX = ++i;
	while (format[i] && ft_check_option(format[i], ALL_SIZES))
		i++;
	if (!(SIZE = ft_strsub(format, INDEX, i - INDEX)))
		exit(EXIT_FAILURE);
	if (format[i] && ft_check_option(format[i], ALL_TYPES))
		return (1);
	return (-1);
}
