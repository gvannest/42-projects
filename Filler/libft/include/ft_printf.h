/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:43:06 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/13 17:15:58 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <wchar.h>
# include "libft.h"
# include <limits.h>

# define BUF_SIZE 1024
# define ALL_TYPES "sSpdDioObuUxXcC%"
# define ALL_FLAGS "-+#0 "
# define ALL_SIZES "hhlljz"
# define INDEX p->index
# define INDEX_BUF p->index_buf
# define TYPE p->type
# define FLAGS p->flags
# define WIDTH p->width
# define PRECISION p->precision
# define PRECISION_ON p->precision_on
# define SIZE p->size
# define FLAGS p->flags
# define BUF p->buf
# define COULEUR p->couleur

# define NO_FLAG 0
# define MINUS 1
# define PLUS (1 << 1)
# define HASH (1 << 2)
# define ZERO (1 << 3)
# define SPACE (1 << 4)

# define H (1)
# define HH (1 << 1)
# define L (1 << 2)
# define LL (1 << 3)
# define J (1 << 4)
# define Z (1 << 5)

typedef struct	s_lst
{
	size_t		index;
	char		type;
	char		buf[BUF_SIZE];
	char		flags;
	char		size;
	size_t		width;
	size_t		precision;
	int			precision_on;
	int			index_buf;
	char		couleur[10];
}				t_lst;

int				ft_printf(const char *format, ...);
void			ft_init_struct(t_lst *p);
void			ft_buffer(const char c, t_lst *p);
int				ft_control_flags(const char *format, t_lst *p);
void			ft_clean_options(t_lst *p);
void			ft_free_struct(t_lst *p);
intmax_t		ft_cast_nsigned(t_lst *p, va_list ap);
uintmax_t		ft_cast_nunsigned(t_lst *p, va_list ap);
wchar_t			ft_cast_char(t_lst *p, va_list ap);
wchar_t			*ft_cast_string(t_lst *p, va_list ap);
int				ft_type_di(t_lst *p, va_list ap);
int				ft_type_u(t_lst *p, va_list ap);
int				ft_type_s(t_lst *p, va_list ap);
int				ft_type_o(t_lst *p, va_list ap);
int				ft_type_b(t_lst *p, va_list ap);
int				ft_type_x(t_lst *p, va_list ap);
int				ft_type_c(t_lst *p, va_list ap);
int				ft_type_p(t_lst *p, va_list ap);
int				ft_type_c(t_lst *p, va_list ap);
int				ft_type_unicodec(t_lst *p, va_list ap);
int				ft_type_unicodes(t_lst *p, va_list ap);
int				ft_wcharconv(wchar_t c, char *str);
int				ft_type_percent(t_lst *p, va_list ap);
void			ft_reinit_struct(t_lst *p);
void			ft_couleur(t_lst *p, const char *format);

#endif
