/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_couleur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:28:08 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/13 18:04:35 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*g_colour[12][2] =
{
	{"eoc", "00"},
	{"highlight", "01"},
	{"underline", "04"},
	{"blink", "05"},
	{"black", "30"},
	{"red", "31"},
	{"green", "32"},
	{"yellow", "33"},
	{"blue", "34"},
	{"purple", "35"},
	{"cyan", "36"},
	{"white", "37"},
};

void			ft_couleur(t_lst *p, const char *format)
{
	int		i;
	int		k;
	size_t	m;

	i = 0;
	k = 0;
	m = INDEX;
	while (format[++INDEX] != '}')
		COULEUR[i++] = format[INDEX];
	INDEX++;
	i = 0;
	while (i < 12 && ft_strcmp(COULEUR, g_colour[i][0]))
		i++;
	if (i != 12)
	{
		ft_buffer('\033', p);
		ft_buffer('[', p);
		while (*(g_colour[i][1] + k))
			ft_buffer(*(g_colour[i][1] + k++), p);
		ft_buffer('m', p);
	}
	else
		INDEX = m;
	(i == 12 ? ft_buffer(format[INDEX++], p) : 1);
}
