/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:20:28 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/03 14:20:30 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "checker.h"

typedef struct  s_algo
{
    char        *ope;
    char        flag;
    int         *tab_sorted;
    int         len_tab;
    int         *medians;
    int         curr_median_idx;
    t_stack     *new_stacka_end;
}               t_algo;

void            ft_algorithm(t_stack **tab_stack);
void            ft_sorting_algo(t_stack **tab_stack, t_algo *algo);
void            ft_sort_tab(t_stack *stack_a, t_algo *algo);
int             ft_is_sorted(t_stack *stack);
void            ft_apply_operations(t_stack **tab_stack, char *ope);
void            ft_sortmerge_stacka(t_stack **tab_stack, t_algo *algo);


#endif
