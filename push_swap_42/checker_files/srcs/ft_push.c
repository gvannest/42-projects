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

static int        ft_push(t_stack **stack_from, t_stack **stack_to, t_stack **stack_to_end)
{
    t_stack *tmp;

    if (!stack_from || !(*stack_from))
        return (0);
    else
    {
        tmp = (*stack_from);
        *stack_from = (*stack_from)->next;
        tmp->next = 0;
        ft_add_stackbeg(tmp, stack_to, stack_to_end);
    }
    return (1);
}

void                ft_push_a(t_stack **tab_stack, t_oper **oper_start)
{
    t_oper *new_oper;

    if (ft_push(&tab_stack[2], &tab_stack[0], &tab_stack[1]))
    {
        if (oper_start)
        {
            new_oper = ft_opernew("pa");
            ft_add_oper(new_oper, oper_start);
        }
    }
}

void                ft_push_b(t_stack **tab_stack, t_oper **oper_start)
{
    t_oper *new_oper;

    if (ft_push(&tab_stack[0], &tab_stack[2], &tab_stack[3]))
    {
        if (oper_start)
        {
            new_oper = ft_opernew("pb");
            ft_add_oper(new_oper, oper_start);
        }
    }
}