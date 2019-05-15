/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:44:35 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/03 17:44:37 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_stacklen(t_stack *list)
{
    int k;

    k = 0;
    if (list == 0)
        return (0);
    while (list)
    {
        k++;
        list = list->next;
    }
    return (k);
}

t_stack	    *ft_stacknew(int n)
{
    t_stack *list;

    if (!(list = (t_stack*)malloc(sizeof(*list))))
        return (0);
    list->nbr = n;
    list->next = NULL;
    return (list);
}

void	    ft_add_stackend(t_stack *new, t_stack **stack_start, t_stack **stack_end)
{
    if (stack_start == 0 || new == 0 || stack_end == 0)
        return ;
    if (*stack_start == 0)
    {
        *stack_start = new;
        *stack_end = new;
    }
    else
    {
        (*stack_end)->next = new;
        *stack_end = new;
    }
}

void	    ft_add_stackbeg(t_stack *new, t_stack **stack_start)
{
    if (stack_start == 0 || new == 0)
        return ;
    if (*stack_start == 0)
        *stack_start = new;
    else
    {
        new->next = *stack_start;
        *stack_start = new;
    }
}