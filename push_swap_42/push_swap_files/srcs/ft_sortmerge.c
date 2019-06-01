/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:00:03 by gvannest          #+#    #+#             */
/*   Updated: 2019/06/01 11:59:25 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/push_swap.h"

static void	ft_empty_b(t_stack **tab_stack, t_oper **oper)
{
	while (ft_stacklen(tab_stack[2], 0))
	{
		if (ft_stacklen(tab_stack[2], 0) > 1
				&& tab_stack[2]->next->nbr > tab_stack[2]->nbr)
			ft_apply_operations(tab_stack, oper, "sb");
		ft_apply_operations(tab_stack, oper, "pa");
	}
}

void		ft_sortmerge_stacka(t_stack **tab_stack, t_algo *algo,
			t_oper **oper)
{
	int	i;

	i = 0;
	if (ft_stacklen(tab_stack[0], 0) > 1
			&& tab_stack[0]->next->nbr < tab_stack[0]->nbr)
		ft_apply_operations(tab_stack, oper, "sa");
	if (ft_stacklen(tab_stack[2], 0) > 1
			&& tab_stack[2]->next->nbr > tab_stack[2]->nbr)
		ft_apply_operations(tab_stack, oper, "sb");
	if (algo->curr_median_idx < 1)
		ft_empty_b(tab_stack, oper);
	else
	{
		while (tab_stack[2]->nbr >= algo->medians[algo->curr_median_idx - 1])
			ft_apply_operations(tab_stack, oper, "pa");
		algo->curr_median_idx -= 2;
		while (algo->tab_sorted[i] != algo->medians[algo->curr_median_idx + 1])
			i++;
		algo->len_tab = i;
		algo->new_stacka_end = tab_stack[0];
	}
}
