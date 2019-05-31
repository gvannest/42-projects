/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:12:33 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/03 15:12:35 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/checker.h"

static void	ft_stackdel(t_stack *stack_a_start)
{
    t_stack *list1;
    t_stack *list2;

    list1 = stack_a_start;
    if (stack_a_start == 0)
        return ;
    while (list1) {
        list2 = list1;
        list1 = list1->next;
        free(list2);
        list2 = 0;
    }
    stack_a_start = 0;
}

static void	ft_operdel(t_oper *oper)
{
    t_oper *list1;
    t_oper *list2;

    list1 = oper;
    if (oper == 0)
        return ;
    while (list1)
    {
        list2 = list1;
        list1 = list1->next;
        ft_strdel(&(list2->instruction));
        free(list2);
    }
    oper = 0;
}

void        ft_clear_all(char *line, char **ptr, t_oper *oper_start, t_stack **tab_stack)
{
    int     i;

    i = 0;
    if (ptr)
    {
        while (ptr[i])
            ft_strdel(&ptr[i++]);
        free(ptr);
    }
    if (tab_stack)
    {
        tab_stack[0] ? ft_stackdel(tab_stack[0]) : 0;
        tab_stack[2] ? ft_stackdel(tab_stack[2]) : 0;
    }
    line ? ft_strdel(&line) : 0;
    oper_start ? ft_operdel(oper_start) : 0;

}

void     ft_errors(char *line, char **ptr, t_oper *oper_start, t_stack **tab_stack)
{
    ft_dprintf(2, "Error\n");
    ft_clear_all(line, ptr, oper_start, tab_stack);
    exit(EXIT_SUCCESS);
}

void	ft_clear_operations(t_oper *oper)
{
    t_oper *list1;
    t_oper *list2;

    list1 = oper;
    if (oper == 0)
        return ;
    while (list1)
    {
        list2 = list1;
        list1 = list1->next;
        free(list2);
    }
    oper = 0;
}