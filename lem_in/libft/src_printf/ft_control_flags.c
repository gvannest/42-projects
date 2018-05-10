/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:00:37 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/10 16:16:14 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check_opt(const char *c, char *option)
{
	size_t i;

	i = 0;
	while (option[i])
	{
		if (option[0] == 'h' && *c == option[i] && (*c == *(c + 1)))
			return (i + 1);
		else if (*c == option[i])
			return (i);
		i++;
	}
	return (-1);
}

static void		ft_search_type(const char c, t_lst *p)
{
	size_t	j;

	j = 0;
	while (ALL_TYPES[j])
	{
		if (c == ALL_TYPES[j])
		{
			TYPE = ALL_TYPES[j];
			return ;
		}
		j++;
	}
}

static	void	ft_point(const char *format, t_lst *p)
{
	PRECISION = ft_atoi(&format[++INDEX]);
	PRECISION_ON = 1;
	while (format[INDEX] && ft_isdigit(format[INDEX]))
		INDEX++;
}

int				ft_control_flags(const char *format, t_lst *p)
{
	int		j;

	INDEX++;
	while (format[INDEX] && (j = ft_check_opt(format + INDEX, ALL_FLAGS)) >= 0)
	{
		FLAGS = FLAGS | (1 << j);
		INDEX++;
	}
	ft_clean_options(p);
	WIDTH = ft_atoi(format + INDEX);
	while (format[INDEX] && ft_isdigit(format[INDEX]))
		INDEX++;
	(format[INDEX] == '.' ? ft_point(format, p) : INDEX);
	while (format[INDEX] && (j = ft_check_opt(format + INDEX, ALL_SIZES)) >= 0)
	{
		SIZE = SIZE | (1 << j);
		INDEX++;
	}
	if (format[INDEX] && ft_check_opt(format + INDEX, ALL_TYPES) >= 0)
	{
		ft_search_type(format[INDEX], p);
		return (0);
	}
	else
		return (-1);
}
