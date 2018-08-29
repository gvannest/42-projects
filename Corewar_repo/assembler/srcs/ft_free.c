/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:26:45 by srossi            #+#    #+#             */
/*   Updated: 2018/08/01 18:28:00 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	ft_free_info(t_asm *info)
{
	if (info->code)
		ft_strdel(&info->code);
	if (info->err_log)
		ft_strdel(&info->err_log);
	if (info->true_name)
		ft_strdel(&info->true_name);
	if (info->path)
		ft_strdel(&info->path);
}

void			ft_free(t_asm *info)
{
	ft_token_list_free(info->atoken);
	ft_free_info(info);
}
