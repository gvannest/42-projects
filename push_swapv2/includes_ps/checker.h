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

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct		s_stack
{
	int				nbr;
	struct s_stack	*next;

}					t_stack;

typedef struct		s_oper
{
	char			*instruction;
	struct s_oper	*next;
}					t_oper;

void				ft_add_input(char *argv_i, t_stack **tab_stack);
void				ft_check_dup(int new_nbr, t_stack **tab_stack,
					char **ptr_argv);

void				ft_add_stackend(t_stack *new, t_stack **stack_start,
					t_stack **stack_end);
void				ft_add_stackbeg(t_stack *new, t_stack **stack_start,
					t_stack **stack_end);
t_stack				*ft_stacknew(int n);
int					ft_stacklen(t_stack *list, t_stack *stop);

t_oper				*ft_opernew(char *line);
void				ft_add_oper(t_oper *new, t_oper **oper_start);

void				ft_swap_a(t_stack **tab_stack, t_oper **oper_start);
void				ft_swap_b(t_stack **tab_stack, t_oper **oper_start);
void				ft_swap_ss(t_stack **tab_stack, t_oper **oper_start);
void				ft_push_a(t_stack **tab_stack, t_oper **oper_start);
void				ft_push_b(t_stack **tab_stack, t_oper **oper_start);
void				ft_rotate_a(t_stack **tab_stack, t_oper **oper_start);
void				ft_rotate_b(t_stack **tab_stack, t_oper **oper_start);
void				ft_rotate_rr(t_stack **tab_stack, t_oper **oper_start);
void				ft_revrot_a(t_stack **tab_stack, t_oper **oper_start);
void				ft_revrot_b(t_stack **tab_stack, t_oper **oper_start);
void				ft_revrot_rr(t_stack **tab_stack, t_oper **oper_start);

void				ft_check_sort(t_stack **tab_stack);
void				ft_clear_all(char *line, char **ptr, t_oper *oper_start,
					t_stack **tab_stack);
void				ft_errors(char *line, char **ptr, t_oper *oper_start,
					t_stack **tab_stack);
void				ft_print_stacks(t_stack *stack);
void				ft_print_oper(t_oper *oper);

#endif
