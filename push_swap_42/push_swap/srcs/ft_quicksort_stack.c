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

static int      ft_check_further(t_stack **tab_stack, int median, char flag)
{
    t_stack *stack;

    stack = 0;
    if (flag == 'a')
    {
        stack = tab_stack[0];
        while (stack)
        {
            if (stack->nbr < median)
                return (1);
            stack = stack->next;

        }
    }
    else if (flag == 'b')
    {
        stack = tab_stack[2];
        while (stack)
        {
            if (stack->nbr > median)
                return (1);
            stack = stack->next;
        }
    }
    return (0);
}

int             ft_new_median(int median, char flag, t_algo *algo)
{
    int i;

    i = 0;
    while (algo->tab_sorted[i] != median)
        i++;
    if (flag == 'b')
        return algo->tab_sorted[((algo->len_tab) - 1 - i) / 2];
    else
        return algo->tab_sorted[i / 2];
}

static void            ft_workona(t_stack **tab_stack, int median)
{
    ft_printf("J'entre dans workona\n");
    ft_printf("%d\n", median);
    ft_printf("Stack a :\n");
    ft_print_stacks(tab_stack[0]);
    ft_printf("Stack b :\n");
    ft_print_stacks(tab_stack[2]);

    while (tab_stack[0]->nbr > median)
        ft_apply_operations(tab_stack, "ra");
    if (tab_stack[0]->nbr == median)
    {
        ft_apply_operations(tab_stack, "pb");
        ft_apply_operations(tab_stack, "rb");
    }
    else
        ft_apply_operations(tab_stack, "pb");
}

static void            ft_workonb(t_stack **tab_stack, int median)
{
    ft_printf("J'entre dans workonb\n");
    ft_printf("%d\n", median);
    ft_printf("Stack a :\n");
    ft_print_stacks(tab_stack[0]);
    ft_printf("Stack b :\n");
    ft_print_stacks(tab_stack[2]);

    while (tab_stack[2]->nbr < median)
        ft_apply_operations(tab_stack, "rb");
    if (tab_stack[2]->nbr == median)
    {
        ft_apply_operations(tab_stack, "pa");
        ft_apply_operations(tab_stack, "ra");
    }
    else
        ft_apply_operations(tab_stack, "pa");
}

void            ft_sorting_algo(t_stack **tab_stack, t_algo *algo, int median, char flag)
{
    char c = 0;

    ft_printf("%c\n", flag);
    ft_printf("%d\n", median);
    ft_printf("Stack a :\n");
    ft_print_stacks(tab_stack[0]);
    ft_printf("Stack b :\n");
    ft_print_stacks(tab_stack[2]);

    if (ft_is_sorted(tab_stack)) {
        return;
    }
    while (ft_check_further(tab_stack, median, flag))
    {
        ft_printf("J'entre dans la boucle check_further\n");
        scanf("%c", &c);
        if (flag == 'a') {
            ft_workona(tab_stack, median);
        }
        else {
            ft_workonb(tab_stack, median);
        }
    }
    if (flag == 'a' && ft_stacklen(tab_stack[2]))
    {
        ft_printf("J'entre dans la boucle passage au sorting de b\n");
        scanf("%c", &c);
        ft_apply_operations(tab_stack, "rrb");
        ft_sorting_algo(tab_stack, algo, ft_new_median(median, flag, algo), 'b');
    }
    else if (flag == 'b' && ft_stacklen(tab_stack[0]))
    {
        ft_printf("J'entre dans la boucle passage au sorting de a\n");
        scanf("%c", &c);
        ft_apply_operations(tab_stack, "rra");
        ft_sorting_algo(tab_stack, algo, ft_new_median(median, flag, algo), 'a');
    }
}