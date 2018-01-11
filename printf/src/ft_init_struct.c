/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:55:36 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/10 21:02:47 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct(t_lst *p)
{
	ft_bzero(p, sizeof(*p));
	if (!(ALL_TYPES = ft_strdup(ALL_TYPES_STRING)))
		exit(EXIT_FAILURE);
	if (!(ALL_FLAGS = ft_strdup(ALL_FLAGS_STRING)))
		exit(EXIT_FAILURE);
	if (!(ALL_SIZES = ft_strdup(ALL_SIZES_STRING)))
		exit(EXIT_FAILURE);
}
