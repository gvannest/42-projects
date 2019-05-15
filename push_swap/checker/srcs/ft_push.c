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

#include "checker.h"

static void        ft_push(t_stack **stack_from, t_stack **stack_to)
{
    t_stack *tmp;

    if (!stack_from || !(*stack_from))
        return;
    else
    {
        tmp = (*stack_from);
        *stack_from = (*stack_from)->next;
        tmp->next = 0;
        ft_add_stackbeg(tmp, stack_to);
    }
}

void                ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
    ft_push(stack_b, stack_a);
}

void                ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
    ft_push(stack_a, stack_b);
}