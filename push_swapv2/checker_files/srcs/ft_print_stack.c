/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:19:56 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/31 20:13:12 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/checker.h"

void			ft_print_stacks(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->nbr);
		stack = stack->next;
	}
	ft_putchar('\n');
}

void			ft_print_oper(t_oper *oper)
{
	while (oper)
	{
		ft_printf("%s\n", oper->instruction);
		oper = oper->next;
	}
	ft_putchar('\n');
}
