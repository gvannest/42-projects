/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reinit_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:15:33 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/12 14:46:21 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reinit_struct(t_lst *p)
{
	TYPE = 0;
	FLAGS = 0;
	SIZE = 0;
	WIDTH = 0;
	PRECISION = 0;
	PRECISION_ON = 0;
	ft_bzero(COULEUR, sizeof(COULEUR));
}
