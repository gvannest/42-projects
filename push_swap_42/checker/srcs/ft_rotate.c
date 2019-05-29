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

static void    ft_rotate(t_stack **stack_start, t_stack **stack_end, char *ope)
{
    t_stack *tmp;

    if (!stack_start || !(*stack_start) || ft_stacklen(*stack_start, 0) == 0 ||
        ft_stacklen(*stack_start, 0) == 1)
        return ;
    else
    {
        tmp = (*stack_start)->next;
        (*stack_start)->next = 0;
        (*stack_end)->next = *stack_start;
        *stack_end = *stack_start;
        *stack_start = tmp;
        ope ? ft_printf("%s\n", ope) : 0;
    }
}

void                ft_rotate_a(t_stack **tab_stack)
{
    ft_rotate(&tab_stack[0], &tab_stack[1], "ra");
}

void                ft_rotate_b(t_stack **tab_stack)
{
    ft_rotate(&tab_stack[2], &tab_stack[3], "rb");
}

void                ft_rotate_rr(t_stack **tab_stack)
{
    ft_rotate(&tab_stack[0], &tab_stack[1], 0);
    ft_rotate(&tab_stack[2], &tab_stack[3], "rr");
}