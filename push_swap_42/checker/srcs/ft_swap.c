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

static void    ft_swap(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !(*stack) || ft_stacklen(*stack) == 0 ||
        ft_stacklen(*stack) == 1)
        return ;
    else
    {
        tmp = (*stack)->next;
        (*stack)->next = tmp->next;
        tmp->next = *stack;
        *stack = tmp;
    }
}

void            ft_swap_a(t_stack **tab_stack)
{
    ft_swap(&tab_stack[0]);
}

void            ft_swap_b(t_stack **tab_stack)
{
    ft_swap(&tab_stack[2]);
}

void            ft_swap_ss(t_stack **tab_stack)
{
    ft_swap(&tab_stack[0]);
    ft_swap(&tab_stack[2]);
}