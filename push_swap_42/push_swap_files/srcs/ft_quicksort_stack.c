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
    int     count;

    stack = 0;
    count = 0;
    if (algo->flag == 'a')
    {
        stack = tab_stack[0];
        while (stack != algo->new_stacka_end)
        {
            if (stack->nbr <= algo->medians[algo->curr_median_idx])
                count++;
            stack = stack->next;
        }
    }
    else if (algo->flag == 'b')
    {
        stack = tab_stack[2];
        while (stack)
        {
            if (stack->nbr >= algo->medians[algo->curr_median_idx])
                count++;
            stack = stack->next;
        }
    }
    return (count);
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

static void            ft_workona(t_stack **tab_stack, t_algo *algo, t_oper **oper)
{
    int median;
    int count_ra;

    count_ra = 0;
    median = algo->medians[algo->curr_median_idx];
    while (ft_check_further(tab_stack, algo))
    {
        while (tab_stack[0]->nbr > median)
        {
            ft_apply_operations(tab_stack, oper, "ra");
            count_ra++;
        }
        if (tab_stack[0]->nbr == median)
        {
            ft_apply_operations(tab_stack, oper, "pb");
            (ft_check_further(tab_stack, algo) > 1) ? ft_apply_operations(tab_stack, oper, "rb") : 0;
        }
        else
            ft_apply_operations(tab_stack, oper, "pb");

    }
    if (tab_stack[3]->nbr == median)
        ft_apply_operations(tab_stack, oper, "rrb");
    else if (ft_stacklen(tab_stack[2], 0) > 1 && tab_stack[2]->next->nbr > tab_stack[2]->nbr)
        ft_apply_operations(tab_stack, oper, "sb");
    if (algo->new_stacka_end) // on reverse les ra que si on a deja fait un passage sur A, ce qui veut dire que le bas de a est trié
    {
        while (count_ra)
        {
            ft_apply_operations(tab_stack, oper, "rra");
            count_ra--;
        }
    }
}

static void            ft_workonb(t_stack **tab_stack, t_algo *algo, t_oper **oper)
{
    int median;
    int count_rb;

    count_rb = 0;
    median = algo->medians[algo->curr_median_idx];
    while (ft_check_further(tab_stack, algo))
    {
        while (tab_stack[2]->nbr < median)
        {
            ft_apply_operations(tab_stack, oper, "rb");
            count_rb++;
        }
        if (tab_stack[2]->nbr == median)
        {
            ft_apply_operations(tab_stack, oper, "pa");
            (ft_check_further(tab_stack, algo) > 1) ? ft_apply_operations(tab_stack, oper, "ra") : 0;
        }
        else
            ft_apply_operations(tab_stack, oper, "pa");

    }
    if (tab_stack[1]->nbr == median)
        ft_apply_operations(tab_stack, oper, "rra");
    else if (ft_stacklen(tab_stack[0], 0) > 1 && tab_stack[0]->next->nbr < tab_stack[0]->nbr)
        ft_apply_operations(tab_stack, oper, "sa");
    while (count_rb)
    {
        ft_apply_operations(tab_stack, oper, "rrb");
        count_rb--;
    }
}

void            ft_sorting_algo(t_stack **tab_stack, t_algo *algo, t_oper **oper)
{
//    ft_printf("current median index ---> %d\n", algo->curr_median_idx);
//    algo->curr_median_idx > -1 ? ft_printf("current median ---> %d\n", algo->medians[algo->curr_median_idx]) : 0;
//    algo->new_stacka_end ? ft_printf("new_end a ---> %d\n", algo->new_stacka_end->nbr) : 0;
//    ft_printf("Stack_A before : \n");
//    ft_print_stacks(tab_stack[0]);
//    ft_printf("======================\n");
//    ft_printf("Stack_B before: \n");
//    ft_print_stacks(tab_stack[2]);

    if (ft_is_sorted(tab_stack[0]) && !ft_stacklen(tab_stack[2], 0))
        return;
    if (ft_stacklen(tab_stack[0], algo->new_stacka_end)) // si je n'ai pas de nouveau sur A je passe direct sur B
    {
        if (ft_stacklen(tab_stack[0], algo->new_stacka_end) <= 2 || ft_is_sorted(tab_stack[0])) // si j'ai du nouveau et qu'il y a moins de 2 elements je trie
            ft_sortmerge_stacka(tab_stack, algo, oper);
        else // s'il y a du nouveau et plus de 2 elements, je repars sur a
        {
            algo->flag = 'a';
            ft_new_median(algo);
            ft_workona(tab_stack, algo, oper);
            ft_sorting_algo(tab_stack, algo, oper);
        }
    }
    if (ft_stacklen(tab_stack[2], 0) > 2) {
        algo->flag = 'b';
        ft_new_median(algo);
        ft_workonb(tab_stack, algo, oper);
        ft_sorting_algo(tab_stack, algo, oper);
    } else if (ft_stacklen(tab_stack[2], 0))
        ft_sortmerge_stacka(tab_stack, algo, oper);
}