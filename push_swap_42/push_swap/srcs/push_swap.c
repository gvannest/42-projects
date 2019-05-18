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

int             main(int argc, char **argv)
{
    t_stack         *tab_stack[5];

    ft_initialize_stacks(tab_stack);
    if (argc < 2)
    {
        ft_dprintf(2, "Error\n");
        return (0);
    }
    ft_parse_stack(tab_stack, argc, argv);


//    ft_printf("Stack_A before : \n");
//    ft_print_stacks(tab_stack[0]);
//    ft_printf("======================\n");
//    ft_printf("Stack_B before: \n");
//    ft_print_stacks(tab_stack[2]);

    ft_algorithm(tab_stack);

//    ft_printf("======================\n");
//    ft_printf("Stack_A after : \n");
//    ft_print_stacks(tab_stack[0]);
//    ft_printf("======================\n");
//    ft_printf("Stack_B after: \n");
//    ft_print_stacks(tab_stack[2]);
//
//    ft_check_sort(tab_stack);

//    ft_clear_all(0, 0, oper, tab_stack);

    return (0);
}

//__attribute__ ((destructor)) void ft_des() {
//    while (1);
//}
