/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:19:56 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/03 14:19:58 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/checker.h"
#include "../../includes_ps/tabptrope.h"

static void     ft_parse_stack(t_stack **tab_stack, int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        ft_add_input(argv[i], tab_stack);
        i++;
    }
}

static void     ft_parse_oper(t_oper **oper_start, t_stack **tab_stack)
{
    char    *line;
    t_oper  *new_oper;
    int     i;
    short   found;

    line = 0;
    while (get_next_line(0, &line))
    {
        i = 0;
        found = 0;
        if (!line[0])
            break;
        while (i < SIZE_OPE)
        {
            if (!ft_strcmp(line, tabope[i].ope))
                found += 1;
            i++;
        }
        if (!found)
            ft_errors(line, 0, *oper_start, tab_stack);
        new_oper = ft_opernew(line);
        ft_add_oper(new_oper, oper_start);
        line = 0;
    }
    (line && !line[0]) ? ft_strdel(&line) : 0;
}

static void     ft_apply_operations(t_stack **tab_stack, t_oper *oper)
{
    int i;

    while (oper)
    {
        i = 0;
        while (i < SIZE_OPE) {
            if (!ft_strcmp(oper->instruction, tabope[i].ope))
                tabope[i].ft_ps_ope(tab_stack, 0);
            i++;
        }
        oper = oper->next;
    }
}

static t_stack  **ft_initialize_stacks(t_stack** tab_stack)
{
    t_stack     *stack_a_start;
    t_stack     *stack_a_end;
    t_stack     *stack_b_start;
    t_stack     *stack_b_end;

    stack_a_start = 0;
    stack_a_end = 0;
    stack_b_start = 0;
    stack_b_end = 0;

    tab_stack[0] = stack_a_start;
    tab_stack[1] = stack_a_end;
    tab_stack[2] = stack_b_start;
    tab_stack[3] = stack_b_end;
    tab_stack[4] = 0;

    return (tab_stack);
}

int             main(int argc, char **argv)
{
    t_stack         *tab_stack[5];
    t_oper          *oper;

    oper = 0;
    ft_initialize_stacks(tab_stack);
    if (argc < 2)
    {
        ft_dprintf(2, "Error\n");
        return (0);
    }
    ft_parse_stack(tab_stack, argc, argv);
    ft_parse_oper(&oper, &tab_stack[0]);
    ft_apply_operations(tab_stack, oper);
    ft_check_sort(tab_stack);
    ft_clear_all(0, 0, oper, tab_stack);
    return (0);
}