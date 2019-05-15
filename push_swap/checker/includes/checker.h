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
void	            ft_add_stackbeg(t_stack *new, t_stack **stack_start);
t_stack	            *ft_stacknew(int n);
int		            ft_stacklen(t_stack *list);

void                ft_swap_a(t_stack **stack_a, t_stack **stack_b);
void                ft_swap_b(t_stack **stack_a, t_stack **stack_b);
void                ft_swap_ss(t_stack **stack_a, t_stack **stack_b);
void                ft_push_a(t_stack **stack_a, t_stack **stack_b);
void                ft_push_b(t_stack **stack_a, t_stack **stack_b);

#endif
