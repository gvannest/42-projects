/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:12:53 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/10 19:16:08 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_clean_option(t_lst *p)
{
	int		i;
	int		j;
	char	*update_flags;

	i = 0;
	j = 0;
	update_flags = ft_strnew(5);
	while (ALL_FLAGS[i] && i < 3)
	{
		if (ft_strchr(FLAGS, ALL_FLAGS[i]))
			update_flags[j++] = ALL_FLAGS[i];
		i++;
	}
	if (ft_strchr(FLAGS, '0') && !ft_strchr(FLAGS, '-'))
		update_flags[j++] = '0';
	if (ft_strchr(FLAGS, ' ') && !ft_strchr(FLAGS, '+'))
		update_flags[j++] = ' ';
	free(FLAGS);
	FLAGS = update_flags;
}

static int	ft_clean_size(t_lst *p)
{
	size_t len;

	len = ft_strlen(SIZE);
	if (len > 2)
		return (-1);
	if (len == 0 || len == 1)
		return (1);
	if ((SIZE[0] == 'h' && SIZE[1] == 'h') || (SIZE[0] == 'l' &&
		SIZE[1] == 'l'))
		return (1);
	return (-1);
}

int			ft_clean_flags(t_lst *p)
{
	ft_clean_option(p);
	if (ft_clean_size(p) < 0)
		return (-1);
	return (1);
}
