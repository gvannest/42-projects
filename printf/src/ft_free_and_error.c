/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:36:12 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/11 11:37:12 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_struct(t_lst *p)
{
	ft_memdel((void*)&ALL_TYPES);
	ft_memdel((void*)&ALL_FLAGS);
	ft_memdel((void*)&FLAGS);
	ft_memdel((void*)&SIZE);
	ft_memdel((void*)&ALL_SIZES);
}

void	ft_error(t_lst *p)
{
	ft_putendl("Error usage.");
	ft_free_struct(p);
}
