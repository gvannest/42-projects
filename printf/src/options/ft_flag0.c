/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:36:37 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/11 18:14:33 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag0(t_lst *p)
{
	size_t k;

	if (PRECISION != 0 || WIDTH == 0)
		return (1);
	if (TYPE == 's' || TYPE == 'S' || TYPE == 'p' || TYPE == 'c' ||
		TYPE == 'C')
		return (-1);
	if (TYPE == 'd' || 'TYPE == 'D' TYPE == 'i')
		k = ft_strlen(ft_itoa_base_s((intmax_t)(PARAM), 10));
	else if(TYPE == 'u' || 'TYPE == 'U')
		k = ft_strlen(ft_itoa_base_s((uintmax_t)(PARAM), 10));
	else if (TYPE == 'o' || 'TYPE == 'O')
		k = ft_strlen(ft_itoa_base_s((uintmax_t)(PARAM), 8));
	else if (TYPE == 'd' || 'TYPE == 'D' TYPE == 'i')
		k = ft_strlen(ft_itoa_base_s((uintmax_t)(PARAM), 16));
	if (WIDTH - k > 0)
	{

	return (1);
}
	
	
	
	
