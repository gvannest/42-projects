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

static int    ft_revrot(t_stack **stack_start, t_stack **stack_end)
{
    t_stack *tmp_end;

    if (!stack_start || !(*stack_start) || ft_stacklen(*stack_start, 0) == 0 ||
        ft_stacklen(*stack_start, 0) == 1)
        return (0);
    else
    {
        tmp_end = (*stack_start);
        while (tmp_end->next != *stack_end)
            tmp_end = tmp_end->next;
        tmp_end->next = NULL;
        (*stack_end)->next = *stack_start;
        *stack_start = *stack_end;
        (*stack_end) = tmp_end;
    }
    return (1);
}

void                ft_revrot_a(t_stack **tab_stack, t_oper **oper_start)
{
    t_oper *new_oper;

    if (ft_revrot(&tab_stack[0], &tab_stack[1]))
    {
        if (oper_start)
        {
            new_oper = ft_opernew("rra");
            ft_add_oper(new_oper, oper_start);
        }
    }
}

void                ft_revrot_b(t_stack **tab_stack, t_oper **oper_start)
{
    t_oper *new_oper;

    if (ft_revrot(&tab_stack[2], &tab_stack[3]))
    {
        if (oper_start)
        {
            new_oper = ft_opernew("rrb");
            ft_add_oper(new_oper, oper_start);
        }
    }
}

void                ft_revrot_rr(t_stack **tab_stack, t_oper **oper_start)
{
    (void)oper_start;
    ft_revrot(&tab_stack[0], &tab_stack[1]);
    ft_revrot(&tab_stack[2], &tab_stack[3]);
}