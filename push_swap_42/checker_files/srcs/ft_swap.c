/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:19:56 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/03 14:19:58 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/checker.h"

static int    ft_swap(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !(*stack) || ft_stacklen(*stack, 0) == 0 ||
        ft_stacklen(*stack, 0) == 1)
        return (0);
    else
    {
        tmp = (*stack)->next;
        (*stack)->next = tmp->next;
        tmp->next = *stack;
        *stack = tmp;
    }
    return (1);
}

void            ft_swap_a(t_stack **tab_stack, t_oper **oper_start)
{
    t_oper *new_oper;

    if (ft_swap(&tab_stack[0]))
    {
        if (oper_start)
        {
            new_oper = ft_opernew("sa");
            ft_add_oper(new_oper, oper_start);
        }
    }
}

void            ft_swap_b(t_stack **tab_stack, t_oper **oper_start)
{
    t_oper *new_oper;

    if (ft_swap(&tab_stack[2]))
    {
        if (oper_start)
        {
            new_oper = ft_opernew("sb");
            ft_add_oper(new_oper, oper_start);
        }
    }
}

void            ft_swap_ss(t_stack **tab_stack, t_oper **oper_start)
{
    (void) oper_start;
    ft_swap(&tab_stack[0]);
    ft_swap(&tab_stack[2]);
}