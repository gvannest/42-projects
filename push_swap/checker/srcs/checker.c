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

void            ft_print_stacks(t_stack* stack)
{
    while (stack)
    {
        ft_printf("%d\n", stack->nbr);
        stack = stack->next;
    }
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
    ft_print_stacks(stack_a_start);
    return (0);
}
