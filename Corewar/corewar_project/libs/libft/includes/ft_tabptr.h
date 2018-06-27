/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabptr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:13:31 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/13 16:51:59 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TABPTR_H
# define FT_TABPTR_H

# include "ft_printf.h"

typedef struct	s_tabptr
{
	char		c;
	int			(*f_type)(t_lst*, va_list);
}				t_tabptr;

struct s_tabptr		tabtype[] =
{
	{'d', &ft_type_di},
	{'D', &ft_type_di},
	{'i', &ft_type_di},
	{'u', &ft_type_u},
	{'U', &ft_type_u},
	{'o', &ft_type_o},
	{'O', &ft_type_o},
	{'b', &ft_type_b},
	{'x', &ft_type_x},
	{'X', &ft_type_x},
	{'s', &ft_type_s},
	{'S', &ft_type_unicodes},
	{'c', &ft_type_c},
	{'C', &ft_type_unicodec},
	{'p', &ft_type_p},
	{'%', &ft_type_percent},
};

#endif
