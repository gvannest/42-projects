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

static void        ft_push(t_stack **stack_from, t_stack **stack_to, t_stack **stack_to_end, char *ope)
{
    t_stack *tmp;

    if (!stack_from || !(*stack_from))
        return;
    else
    {
        tmp = (*stack_from);
        *stack_from = (*stack_from)->next;
        tmp->next = 0;
        ft_add_stackbeg(tmp, stack_to, stack_to_end);
        ft_printf("%s\n", ope);
    }
}

void                ft_push_a(t_stack **tab_stack)
{
    ft_push(&tab_stack[2], &tab_stack[0], &tab_stack[1], "pa");
}

void                ft_push_b(t_stack **tab_stack)
{
    ft_push(&tab_stack[0], &tab_stack[2], &tab_stack[3], "pb");
}