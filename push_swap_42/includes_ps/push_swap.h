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
    t_stack     *current_pivot;
    int         *tab_sorted;
    int         len_tab;
}               t_algo;

void            ft_algorithm(t_stack **tab_stack);
void            ft_sorting_algo(t_stack **tab_stack, t_algo *algo, int median, char flag);
void            ft_sort_tab(t_stack *stack_a, t_algo *algo);
int             ft_is_sorted(t_stack **tab_stack);
void            ft_apply_operations(t_stack **tab_stack, char *ope);


#endif
