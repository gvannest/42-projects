/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:49:42 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/16 12:13:26 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int argc, char **argv)
{
	(void)argc;
	char *str;
	str = ft_itoabase_u(ft_atoi(argv[1]), argv[2]);
	ft_putstr(str);
	return (0);
}

