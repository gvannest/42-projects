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

static int          ft_check_ifbigger(t_stack *stack_a, t_stack *stack_b_end)
{
    while (stack_a)
    {
        if (stack_a->nbr > stack_b_end->nbr)
            return (1);
        stack_a = stack_a->next;
    }
    return (0);
}

static char        *ft_push_bigger(t_stack **tab_stack)
{
    if (!ft_check_ifbigger(tab_stack[0], tab_stack[3]))
        return (0);
    if (ft_stacklen(tab_stack[2]) > 1 && tab_stack[2]->nbr < tab_stack[2]->next->nbr)
        return ft_strcpy(ft_strnew(4), "sb");
    if (ft_stacklen(tab_stack[0]) && tab_stack[0]->nbr > tab_stack[3]->nbr)
        return ft_strcpy(ft_strnew(4), "pb");
    if (ft_stacklen(tab_stack[0]) > 2 && tab_stack[0]->next->nbr > tab_stack[3]->nbr)
        return ft_strcpy(ft_strnew(4), "sa");
    if (ft_stacklen(tab_stack[0]) > 2 && tab_stack[1]->nbr > tab_stack[3]->nbr)
        return ft_strcpy(ft_strnew(4), "rra");
    if (ft_stacklen(tab_stack[0]) > 1 && tab_stack[0]->nbr < tab_stack[3]->nbr)
        return ft_strcpy(ft_strnew(4), "ra");
    return (0);
}

static char        *ft_pushback_a(t_stack **tab_stack)
{
    if (ft_stacklen(tab_stack[2]) > 1 && tab_stack[2]->nbr < tab_stack[2]->next->nbr)
        return ft_strcpy(ft_strnew(4), "sb");
//    if (ft_stacklen(tab_stack[0]) > 1 && tab_stack[0]->nbr > tab_stack[0]->next->nbr)
//        return ft_strcpy(ft_strnew(4), "sa");
//    if (ft_stacklen(tab_stack[2]) == 0 && ft_stacklen(tab_stack[0]) > 1)
//        return ft_strcpy(ft_strnew(4), "rra");
    return ft_strcpy(ft_strnew(4), "pa");
}

char        *ft_choose_operation(t_stack **tab_stack, char *b_emp)
{
    char    *ope;

    if (!ft_stacklen(tab_stack[2]) && !(*b_emp))
    {
        *b_emp = 1;
        return ft_strcpy(ft_strnew(4), "rra");
    }
    if (*b_emp && !ft_stacklen(tab_stack[2]))
    {
        if (ft_stacklen(tab_stack[0]) > 1 && tab_stack[0]->nbr > tab_stack[0]->next->nbr)
            return ft_strcpy(ft_strnew(4), "sa");
        return ft_strcpy(ft_strnew(4), "pb");
    }
    if (*b_emp && !(ope = ft_push_bigger(tab_stack)))
    {
        ft_clear_seen(tab_stack[0]);
        *b_emp = 0;
    }
    if (!(*b_emp))
        return (ft_pushback_a(tab_stack));
    return (ope);

}