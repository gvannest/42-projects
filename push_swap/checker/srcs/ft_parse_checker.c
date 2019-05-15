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

#include "checker.h"

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
    while (list1) {
        list2 = list1;
        list1 = list1->next;
        ft_strdel(&(list2->instruction));
        free(list2);
    }
    oper = 0;
}

static void     ft_errors_checker(char **ptr, t_stack *stack_a_start)
{
    int     i;

    i = 0;

    if (ptr)
    {
        while (ptr[i])
        {
            ft_strdel(&ptr[i]);
            i++;
        }
    }
    ft_stackdel(stack_a_start);
    ft_dprintf(2, "Error\n");
    exit(EXIT_SUCCESS);
}

void        ft_add_input(char *argv_i, t_stack **stack_a_beg, t_stack **stack_a_end)
{
    int     j;
    int     i;
    char    **ptr_argv;
    t_stack *new_stacka;

    j = 0;
    ptr_argv = ft_strsplit(argv_i, ' ');
    while (ptr_argv[j])
    {
        i = 0;
        while (ptr_argv[j][i])
        {
            if (!ft_isdigit(ptr_argv[j][i]))
                ft_errors_checker(ptr_argv, *stack_a_beg);
            i++;
        }
        new_stacka = ft_stacknew(ft_atoi(ptr_argv[j]));
        ft_add_stackend(new_stacka, stack_a_beg, stack_a_end);
        j++;
    }
}

void        ft_clear_all(char *line, t_oper **oper_start, t_stack **stack_a)
{
    ft_stackdel(*stack_a);
    ft_strdel(&line);
    ft_operdel(*oper_start);
    stack_a = 0;
    line = 0;
    oper_start = 0;
    ft_dprintf(2, "Error\n");
    exit(EXIT_SUCCESS);
}