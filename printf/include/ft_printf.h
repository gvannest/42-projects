/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:39:46 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/11 18:14:50 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"
# include <limits.h>

# define BUF_SIZE 1000
# define ALL_TYPES_STRING "sSpdDioOuUxXcC%"
# define ALL_FLAGS_STRING "-+#0 "
# define ALL_SIZES_STRING "hljz"
# define INDEX p->index
# define INDEX_BUF p->index_buf
# define ALL_TYPES p->all_types
# define TYPE p->type
# define FLAGS p->flags
# define ALL_FLAGS p->all_flags
# define WIDTH p->width
# define PRECISION p->precision
# define SIZE p->size
# define ALL_SIZES p->all_sizes
# define PARAM p->param
# define PARAM_UNSIGNED p->param_unsigned
# define PARAM_SIGNED p->param_signed

typedef struct	s_lst
{
	void		*param;
	size_t		index;
	char		*all_types;
	char		type;
	char		*flags;
	char		*all_flags;
	int			width;
	int			precision;
	char		*size;
	char		*all_sizes;
	size_t		index_buf;
	char		*result;
}				t_lst;

typedef struct	s_options
{
	char	*str;
	int		(*f_opt)(t_lst *);
}				t_options;

typedef struct	s_type
{
	char	c;
}				t_type;


/* Fonction principale*/
int				ft_printf(const char *format, ...);

/*
 * Cette fonction initialise la structure et permet notamment des
 * proteger les mallocs
*/
void			ft_init_struct(t_lst *p);

/*Fonction qui complete le buffer caractere par caractere 
 * et qui l'imprime lorsque le remplissage est arrive au bout*/
void			ft_buffer(const char *str, char *buf, t_lst *p);

/*Fonction appelee une fois un % trouve qui controle l'ordre des options
 * (flags, puis width puis precision puis size) + leur validite caractere
 * par caractere. Elle return -1 en cas d'erreur ou 1 en cas de succes*/
int				ft_control_flags(const char *format, t_lst *p);

/*fonction qui nettoye les flags d'option - ne prend qu'un des flags
 * plusieurs sont entres, ne prend pas le 0 si - et ne prend pas espace si +
 * - et qui controle les tailles (renvoie une erreur si plus de 2 sizes ou 
 *   si la size est impossible*/
int				ft_clean_flags(t_lst *p);

/*
 * Fonction qui libere les elements malloces de la structure
 */
void			ft_free_struct(t_lst *p);

/*
 * Cette fonction envoie un message d'erreur et free les elements malloces
 * de la structure
 * */
void			ft_error(t_lst *p);


#endif

