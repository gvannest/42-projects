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

#include "checker.h"
#include "tabptrope.h"

void            ft_print_stacks(t_stack* stack)
{
    while (stack)
    {
        ft_printf("%d\n", stack->nbr);
        stack = stack->next;
    }
    ft_putchar('\n');
}

static void     ft_parse_stack(t_stack **stack_a_beg, t_stack **stack_a_end,
                int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        ft_add_input(argv[i], stack_a_beg, stack_a_end);
        i++;
    }
}

static void     ft_apply_operations(t_stack **stack_a, t_stack **stack_b, char list_op[4])
{
    int i;

    i = 0;

    while (i < 5)
    {
        if (!ft_strcmp(list_op, tabope[i].ope))
        {
            tabope[i].ft_ps_ope(stack_a, stack_b);
        }
        i++;
    }
}


int             main(int argc, char **argv)
{
    t_stack     *stack_a_start;
    t_stack     *stack_a_end;
    t_stack     *stack_b_start;
    t_stack     *stack_b_end;

    stack_a_start = 0;
    stack_a_end = 0;
    stack_b_start = 0;
    stack_b_end = 0;

    if (argc < 2)
        ft_dprintf(2, "Error\n");
    else
        ft_parse_stack(&stack_a_start, &stack_a_end, argc, argv);

    ft_printf("======================\n");
    ft_printf("Stack_A before : \n");
    ft_print_stacks(stack_a_start);
    ft_printf("======================\n");
    ft_printf("Stack_B before: \n");
    ft_print_stacks(stack_b_start);

    char operation[4] = "pb";
    ft_apply_operations(&stack_a_start, &stack_b_start, operation);

    ft_printf("======================\n");
    ft_printf("Stack_A after : \n");
    ft_print_stacks(stack_a_start);
    ft_printf("======================\n");
    ft_printf("Stack_B after: \n");
    ft_print_stacks(stack_b_start);

    return (0);
}
