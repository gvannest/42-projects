/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:56:51 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/15 17:26:11 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_base(t_lst *p)
{
	if (TYPE == 'd' || TYPE == 'D' || TYPE == 'i' || TYPE == 'u' || TYPE == 'U')
		BASE = 10;
	else if (TYPE == 'o' || TYPE == 'O')
		BASE = 8;
	else if (TYPE == 'x' || TYPE == 'X')
		BASE = 16;
}


void	ft_length(t_lst *p)
{
	if (TYPE == 's' || TYPE == 'S')
		LEN_PARAM = ft_strlen((char*)PARAM);
	else if (TYPE == 'c' || TYPE == 'C')
		LEN_PARAM = 1;
	else if (TYPE == 'p')
		LEN_PARAM = 14;
	else
	{
		ft_base(p);
		ft_putnbr(BASE);
	//if (TYPE == 'd' || TYPE == 'D' || TYPE == 'i')
		//LEN_PARAM = ft_strlen(ft_itoabase_u(*(intmax_t*)PARAM, BASE));
	//else	
		//LEN_PARAM = ft_strlen(ft_itoabase_u(*(uintmax_t*)PARAM, BASE));
	}
}
