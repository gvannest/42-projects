/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:13:36 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/01 15:42:42 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buffer(const char c, t_lst *p)
{
	if ((INDEX_BUF != 0) && (INDEX_BUF % BUF_SIZE == 0))
	{
		write(1, BUF, BUF_SIZE);
		ft_bzero(BUF, BUF_SIZE);
	}
	BUF[INDEX_BUF % BUF_SIZE] = c;
	INDEX_BUF++;
}
