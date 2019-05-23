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


int      ft_is_sorted(t_stack **tab_stack)
{
    t_stack *tmp;
    int     prev;
    int     curr;

    prev = 0;
    curr = 0;
    if (ft_stacklen(tab_stack[2]))
        return (0);
    if (ft_stacklen(tab_stack[0]) == 1)
        return (1);
    if (tab_stack[0])
    {
        prev = tab_stack[0]->nbr;
        tmp = tab_stack[0]->next;
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

void     ft_apply_operations(t_stack **tab_stack, char *ope)
{
int i;

    i = 0;
    while (i < SIZE_OPE)
    {
        if (!ft_strcmp(ope, tabope[i].ope))
            tabope[i].ft_ps_ope(tab_stack);
        i++;
    }
}

void            ft_algorithm(t_stack **tab_stack)
{
    t_algo  algo;
    int     median;

    algo.flag = 0;
    algo.current_pivot = 0;
    if(!(algo.tab_sorted = (int*)malloc(sizeof(int) * ft_stacklen(tab_stack[0]))))
        exit(EXIT_FAILURE);
    ft_bzero(algo.tab_sorted, sizeof(int) * ft_stacklen(tab_stack[0]));
    ft_sort_tab(tab_stack[0], &algo);
    median = algo.tab_sorted[(algo.len_tab - 1) / 2];
    ft_sorting_algo(tab_stack, &algo, median, 'a');
}
