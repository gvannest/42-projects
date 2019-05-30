/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabptrope.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:13:31 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/13 16:51:59 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABPTROPE_H
# define TABPTROPE_H

# include "checker.h"

# define SIZE_OPE 11

typedef struct	        s_tabptrope
{
    char		ope[4];
    void        (*ft_ps_ope)(t_stack **, t_oper **);
}				        t_tabptrope;

struct s_tabptrope		tabope[] =
{
    {"sa", &ft_swap_a},
    {"sb", &ft_swap_b},
    {"ss", &ft_swap_ss},
    {"pa", &ft_push_a},
    {"pb", &ft_push_b},
    {"ra", &ft_rotate_a},
    {"rb", &ft_rotate_b},
    {"rr", &ft_rotate_rr},
    {"rra", &ft_revrot_a},
    {"rrb", &ft_revrot_b},
    {"rrr", &ft_revrot_rr},
};

#endif