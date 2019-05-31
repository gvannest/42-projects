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

void            ft_oper_toprint(t_oper *oper)
{
    t_oper *tmp;
    int     i;
    char    tab1[7][4] = {"ra", "rb", "rra", "rrb", "sa", "sb"};
    char    tab2[7][4] = {"rb", "ra", "rrb", "rra", "sb", "sa"};
    char    tab3[7][4] = {"rr", "rr", "rrr", "rrr", "ss", "ss"};

    while (oper)
    {
        tmp = (oper->next) ? oper->next : 0;
        if (tmp)
        {
            i = 0;
            while (i < 6)
            {
                if (!ft_strcmp(oper->instruction, tab1[i])
                && !ft_strcmp(tmp->instruction, tab2[i]))
                {
                    ft_printf("%s\n", tab3[i]);
                    oper = tmp->next;
                    break;
                }
                i++;
            }
            (oper != tmp->next) ? ft_printf("%s\n", oper->instruction) : 0;
            (oper != tmp->next) ? oper = oper->next : 0;
        }
        else
        {
            ft_printf("%s\n", oper->instruction);
            oper = oper->next;
        }
    }
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
    ft_algorithm(tab_stack, &oper);
    ft_oper_toprint(oper);
    ft_clear_operations(oper);
    ft_clear_all(0, 0, 0, tab_stack);

    return (0);
}
