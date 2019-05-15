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

typedef struct	        s_tabptrope
{
    char		ope[4];
    void        (*ft_ps_ope)(t_stack **, t_stack **);
}				        t_tabptrope;

struct s_tabptrope		tabope[] =
{
    {"sa", &ft_swap_a},
    {"sb", &ft_swap_b},
    {"ss", &ft_swap_ss},
    {"pa", &ft_push_a},
    {"pb", &ft_push_b},
};

#endif