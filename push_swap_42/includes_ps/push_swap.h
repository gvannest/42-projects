/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 19:25:48 by gvannest          #+#    #+#             */
/*   Updated: 2019/06/01 12:03:37 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "checker.h"

typedef struct	s_algo
{
	char		flag;
	int			*tab_sorted;
	int			len_tab;
	int			*medians;
	int			curr_median_idx;
	t_stack		*new_stacka_end;
}				t_algo;

void			ft_algorithm(t_stack **tab_stack, t_oper **oper);
void			ft_sorting_algo(t_stack **tab_stack, t_algo *algo,
				t_oper **oper);
void			ft_sort_tab(t_stack *stack_a, t_algo *algo);
int				ft_is_sorted(t_stack *stack);
int				ft_check_further(t_stack **tab_stack, t_algo *algo);
void			ft_apply_operations(t_stack **tab_stack, t_oper **oper,
				char *ope);
void			ft_sortmerge_stacka(t_stack **tab_stack, t_algo *algo,
				t_oper **oper);
void			ft_fixa(t_stack **tab_stack, t_algo *algo, t_oper **oper);
void			ft_clear_operations(t_oper *oper);
int				ft_tools_workona(t_stack **tab_stack, t_algo *algo,
				t_oper **oper);
int				ft_tools_workonb(t_stack **tab_stack, t_algo *algo,
				t_oper **oper);

#endif
