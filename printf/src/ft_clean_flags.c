/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 12:26:18 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/10 12:26:20 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_clean_options(t_lst *p)
{
	if ((FLAGS & MINUS) && (FLAGS & ZERO))
		FLAGS = FLAGS ^ ZERO;
	if ((FLAGS & PLUS) && (FLAGS & SPACE))
		FLAGS = FLAGS ^ SPACE;
}
