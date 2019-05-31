/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 21:15:42 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/31 21:23:38 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/push_swap.h"

void	ft_tools_workona(t_stack **tab_stack, t_algo *algo, t_oper *oper,
		int *count)
{
	int median;

	median = algo->medians[algo->curr_median_idx];
	while (ft_check_further(tab_stack, algo))
	{
		while (tab_stack[0]->nbr > median)
		{
			ft_apply_operations(tab_stack, oper, "ra");
			*count++;
		}
		if (tab_stack[0]->nbr == median)
		{
			ft_apply_operations(tab_stack, oper, "pb");
			(ft_check_further(tab_stack, algo) > 1)
				? ft_apply_operations(tab_stack, oper, "rb") : 0;
		}
		else
			ft_apply_operations(tab_stack, oper, "pb");
	}
}

void	ft_tools_workonb(t_stack **tab_stack, t_algo *algo, t_oper *oper,
		int *count)
{
	int median;

	median = algo->medians[algo->curr_median_idx];
	while (ft_check_further(tab_stack, algo))
	{
		while (tab_stack[2]->nbr < median)
		{
			ft_apply_operations(tab_stack, oper, "rb");
			*count++;
		}
		if (tab_stack[2]->nbr == median)
		{
			ft_apply_operations(tab_stack, oper, "pa");
			(ft_check_further(tab_stack, algo) > 1)
				? ft_apply_operations(tab_stack, oper, "ra") : 0;
		}
		else
			ft_apply_operations(tab_stack, oper, "pa");
	}
}
