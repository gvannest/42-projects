/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:39:46 by gvannest          #+#    #+#             */
/*   Updated: 2017/12/22 15:12:21 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

# define BUF_SIZE 1

typedef struct	s_lst
{
	void		*all;
	int			len;
	int			nb_percent;
}				t_lst;

int				ft_printf(const char *format, ...);

void			ft_lecture(const char *str, char *buf, t_lst *p);

#endif

