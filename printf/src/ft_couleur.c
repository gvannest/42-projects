/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_couleur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:28:08 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/12 15:03:47 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_couleur.h"

void	ft_couleur(t_lst *p, const char *format)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (format[++INDEX] != '}')
		COULEUR[i++] = format[INDEX];
	INDEX++;
	i = 0;
	while (ft_strcmp(COULEUR, tcolour[i].colour_str) != 0 && i < 12)
		i++;
	if (i != 12)
	{
		ft_buffer('\033', p);
		ft_buffer('[', p);
		while ((tcolour[i].colour_nb)[k])
			ft_buffer((tcolour[i].colour_nb)[k++], p);
		ft_buffer('m', p);
	}
}
