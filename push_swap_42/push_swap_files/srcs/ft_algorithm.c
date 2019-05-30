/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:00:03 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/16 14:00:06 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/push_swap.h"
# include "../../includes_ps/tabptrope.h"

int      ft_is_sorted(t_stack *stack)
{
    t_stack *tmp;
    int     prev;
    int     curr;

    prev = 0;
    curr = 0;
    if (ft_stacklen(stack, 0) == 1)
        return (1);
    if (stack)
    {
        prev = stack->nbr;
        tmp = stack->next;
        while (tmp) {
            curr = tmp->nbr;
            if (curr < prev)
                return (0);
            prev = curr;
            tmp = tmp->next;
        }
    }
    return (1);
}

void     ft_apply_operations(t_stack **tab_stack, t_oper **oper, char *ope)
{
int i;

    i = 0;
    while (i < SIZE_OPE)
    {
        if (!ft_strcmp(ope, tabope[i].ope))
            tabope[i].ft_ps_ope(tab_stack, oper);
        i++;
    }
}

void            ft_algorithm(t_stack **tab_stack, t_oper **oper)
{
    t_algo  algo;

    algo.flag = 0;
    if(!(algo.tab_sorted = (int*)malloc(sizeof(int) * ft_stacklen(tab_stack[0], 0))))
        exit(EXIT_FAILURE);
    ft_bzero(algo.tab_sorted, sizeof(int) * ft_stacklen(tab_stack[0], 0));
    ft_sort_tab(tab_stack[0], &algo);
    if(!(algo.medians = (int*)ft_memalloc(sizeof(int) * algo.len_tab)))
        exit(EXIT_FAILURE);
    algo.curr_median_idx = -1;
    algo.new_stacka_end = NULL;
    ft_sorting_algo(tab_stack, &algo, oper);
    //free algo
}
