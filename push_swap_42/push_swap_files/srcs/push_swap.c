/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:00:03 by gvannest          #+#    #+#             */
/*   Updated: 2019/06/01 12:28:34 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/push_swap.h"

static void		ft_parse_stack(t_stack **tab_stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_add_input(argv[i], tab_stack);
		i++;
	}
}

static t_stack	**ft_initialize_stacks(t_stack **tab_stack)
{
	t_stack		*stack_a_start;
	t_stack		*stack_a_end;
	t_stack		*stack_b_start;
	t_stack		*stack_b_end;

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

static int		ft_reduce(t_oper **oper, t_oper **tmp, char *ope1, char *ope2)
{
	if (*tmp)
	{
		if ((!ft_strcmp((*oper)->instruction, ope1)
			&& !ft_strcmp((*tmp)->instruction, ope2))
			|| (!ft_strcmp((*oper)->instruction, ope2)
			&& !ft_strcmp((*tmp)->instruction, ope1)))
		{
			*oper = (*tmp)->next;
			return (1);
		}
	}
	return (0);
}

static void		ft_oper_toprint(t_oper *oper)
{
	t_oper	*tmp;

	while (oper)
	{
		tmp = oper->next;
		if (ft_reduce(&oper, &tmp, "ra", "rb"))
			ft_printf("%s\n", "rr");
		else if (ft_reduce(&oper, &tmp, "rra", "rrb"))
			ft_printf("%s\n", "rrr");
		else if (ft_reduce(&oper, &tmp, "sa", "sb"))
			ft_printf("%s\n", "ss");
		else
		{
			ft_printf("%s\n", oper->instruction);
			oper = oper->next;
		}
	}
}

int				main(int argc, char **argv)
{
	t_stack			*tab_stack[5];
	t_oper			*oper;

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
