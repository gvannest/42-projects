/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabptr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:13:31 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/12 15:03:21 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COULEUR_H
# define FT_COULEUR_H

# include "ft_printf.h"

typedef struct			s_tabcouleur
{
	char				colour_str[10];
	char				colour_nb[3];
}						t_tabcouleur;

struct s_tabcouleur		tcolour[] =
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

#endif
