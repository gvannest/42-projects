/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:36:23 by srossi            #+#    #+#             */
/*   Updated: 2018/06/20 15:47:40 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_param_free(t_param *param)
{
	if (param != NULL)
	{
		if (param->type_name != NULL)
			ft_strdel(&param->type_name);
		if (param->str_value != NULL)
			ft_strdel(&param->str_value);
		free(param);
	}
}
