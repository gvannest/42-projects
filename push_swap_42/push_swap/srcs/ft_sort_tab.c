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

int         ft_partition(int *tab, int start, int end)
{
    int pivot;
    int p_index;

    pivot = tab[end];
    p_index = start;



}


void        ft_quicksort(int *tab, int start, int end)
{
    int p_index;

    p_index = 0;
    if (start < end)
        return;
    p_index = ft_partition(tab, start, end);
}


void        ft_sort_tab(t_stack *stack_a, t_algo *algo)
{
    int i;
    int len;

    i = 0;
    len = ft_stacklen(stack_a);
    while (i < len)
    {
        algo->tab_sorted[i] = stack_a->nbr;
        stack_a = stack_a->next;
        i++;
    }
    ft_quicksort(algo->tab_sorted, 0, len - 1);
}