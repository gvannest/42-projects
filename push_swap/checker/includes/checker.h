/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:20:28 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/03 14:20:30 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

typedef struct      s_stack
{
    int             nbr;
    struct s_stack  *next;

}                   t_stack;

void                ft_add_input(char *argv_i, t_stack **stack_a_beg, t_stack **stack_a_end);
void	            ft_add_stackend(t_stack *new, t_stack **stack_start, t_stack **stack_end);
t_stack	            *ft_stacknew(int n);

#endif
