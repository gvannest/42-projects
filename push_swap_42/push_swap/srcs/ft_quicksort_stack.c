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

static int      ft_check_further(t_stack **tab_stack, t_algo *algo)
{
    t_stack *stack;

    stack = 0;
    if (algo->flag == 'a')
    {
        stack = tab_stack[0];
        while (stack != algo->new_stacka_end)
        {
            if (stack->nbr <= algo->medians[algo->curr_median_idx])
                return (1);
            stack = stack->next;
        }
    }
    else if (algo->flag == 'b')
    {
        stack = tab_stack[2];
        while (stack)
        {
            if (stack->nbr >= algo->medians[algo->curr_median_idx])
                return (1);
            stack = stack->next;
        }
    }
    return (0);
}

void             ft_new_median(t_algo *algo)
{
    int i;
    int new_med;

    i = 0;
    if (algo->curr_median_idx == -1)
    {
        new_med = algo->tab_sorted[(algo->len_tab - 1) / 2];
        algo->medians[0] = new_med;
        algo->curr_median_idx = 0;
        return;
    }
    while (algo->tab_sorted[i] != algo->medians[algo->curr_median_idx])
        i++;
    new_med = algo->tab_sorted[i + ((algo->len_tab) - 1 - i) / 2];
    algo->medians[algo->curr_median_idx + 1] = new_med;
    (algo->curr_median_idx)++;
}

static void            ft_workona(t_stack **tab_stack, t_algo *algo)
{
    int median;
    int count_ra;

    count_ra = 0;
    median = algo->medians[algo->curr_median_idx];
    while (ft_check_further(tab_stack, algo))
    {
        while (tab_stack[0]->nbr > median)
        {
            ft_apply_operations(tab_stack, "ra");
            count_ra++;
        }
        if (tab_stack[0]->nbr == median)
        {
            ft_apply_operations(tab_stack, "pb");
            ft_apply_operations(tab_stack, "rb");
        }
        else
            ft_apply_operations(tab_stack, "pb");

    }
    if (tab_stack[3]->nbr == median)
        ft_apply_operations(tab_stack, "rrb");
    if (algo->new_stacka_end) // on reverse les ra que si on a deja fait un passage sur A, ce qui veut dire que le bas de a est trié
    {
        while (count_ra)
        {
            ft_apply_operations(tab_stack, "rra");
            count_ra--;
        }
    }
}

static void            ft_workonb(t_stack **tab_stack, t_algo *algo)
{
    int median;
    int count_rb;

    count_rb = 0;
    median = algo->medians[algo->curr_median_idx];
    while (ft_check_further(tab_stack, algo))
    {
        while (tab_stack[2]->nbr < median)
        {
            ft_apply_operations(tab_stack, "rb");
            count_rb++;
        }
        if (tab_stack[2]->nbr == median)
        {
            ft_apply_operations(tab_stack, "pa");
            ft_apply_operations(tab_stack, "ra");
        }
        else
            ft_apply_operations(tab_stack, "pa");

    }
    if (tab_stack[1]->nbr == median)
        ft_apply_operations(tab_stack, "rra");
    while (count_rb)
    {
        ft_apply_operations(tab_stack, "rrb");
        count_rb--;
    }
}

void            ft_sorting_algo(t_stack **tab_stack, t_algo *algo)
{
    if (ft_is_sorted(tab_stack[0]) && !ft_stacklen(tab_stack[2], 0))
        return;
    if (ft_stacklen(tab_stack[0], algo->new_stacka_end)) // si je n'ai pas de nouveau sur A je passe direct sur B
    {
        if (ft_stacklen(tab_stack[0], algo->new_stacka_end) <= 2) // si j'ai du nouveau et qu'il y a moins de 2 elements je trie
            ft_sortmerge_stacka(tab_stack, algo);
        else // s'il y a du nouveau et plus de 2 elements, je repars sur a
        {
            algo->flag = 'a';
            ft_new_median(algo);
            ft_workona(tab_stack, algo);
            ft_sorting_algo(tab_stack, algo);
        }
    }
    if (ft_stacklen(tab_stack[2], 0) > 2) {
        algo->flag = 'b';
        ft_new_median(algo);
        ft_workonb(tab_stack, algo);
        ft_sorting_algo(tab_stack, algo);
    } else if (ft_stacklen(tab_stack[2], 0))
        ft_sortmerge_stacka(tab_stack, algo);
}