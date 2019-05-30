/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:19:56 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/03 14:19:58 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/checker.h"

static int    ft_rotate(t_stack **stack_start, t_stack **stack_end)
{
    t_stack *tmp;

    if (!stack_start || !(*stack_start) || ft_stacklen(*stack_start, 0) == 0 ||
        ft_stacklen(*stack_start, 0) == 1)
        return (0);
    else
    {
        tmp = (*stack_start)->next;
        (*stack_start)->next = 0;
        (*stack_end)->next = *stack_start;
        *stack_end = *stack_start;
        *stack_start = tmp;
    }
    return (1);
}

void                ft_rotate_a(t_stack **tab_stack, t_oper **oper_start)
{
    t_oper *new_oper;

    if (ft_rotate(&tab_stack[0], &tab_stack[1]))
    {
        if (oper_start)
        {
            new_oper = ft_opernew("ra");
            ft_add_oper(new_oper, oper_start);
        }
    }
}

void                ft_rotate_b(t_stack **tab_stack, t_oper **oper_start)
{
    t_oper *new_oper;

    if (ft_rotate(&tab_stack[2], &tab_stack[3]))
    {
        if (oper_start)
        {
            new_oper = ft_opernew("rb");
            ft_add_oper(new_oper, oper_start);
        }
    }
}

void                ft_rotate_rr(t_stack **tab_stack, t_oper **oper_start)
{
    (void)oper_start;
    ft_rotate(&tab_stack[0], &tab_stack[1]);
    ft_rotate(&tab_stack[2], &tab_stack[3]);
}