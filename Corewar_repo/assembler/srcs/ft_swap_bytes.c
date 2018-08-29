/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bytes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 11:43:11 by srossi            #+#    #+#             */
/*   Updated: 2018/07/19 12:06:46 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_swap_bytes_int(unsigned char *t)
{
	unsigned char tmp;

	tmp = t[0];
	t[0] = t[3];
	t[3] = tmp;
	tmp = t[1];
	t[1] = t[2];
	t[2] = tmp;
}

void	ft_swap_bytes_short(unsigned char *t)
{
	unsigned char tmp;

	tmp = t[0];
	t[0] = t[1];
	t[1] = tmp;
}
