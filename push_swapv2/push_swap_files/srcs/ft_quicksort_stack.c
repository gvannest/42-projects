/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:00:03 by gvannest          #+#    #+#             */
/*   Updated: 2019/06/01 12:03:56 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/push_swap.h"

int			ft_check_further(t_stack **tab_stack, t_algo *algo)
{
	t_stack	*stack;
	int		count;

	stack = 0;
	count = 0;
	if (algo->flag == 'a')
	{
		stack = tab_stack[0];
		while (stack != algo->new_stacka_end)
		{
			(stack->nbr <= algo->medians[algo->curr_median_idx]) ? count++ : 0;
			stack = stack->next;
		}
	}
	else if (algo->flag == 'b')
	{
		stack = tab_stack[2];
		while (stack)
		{
			(stack->nbr >= algo->medians[algo->curr_median_idx]) ? count++ : 0;
			stack = stack->next;
		}
	}
	return (count);
}

void		ft_new_median(t_algo *algo)
{
	int	i;
	int	new_med;

	i = 0;
	if (algo->curr_median_idx == -1)
	{
		new_med = algo->tab_sorted[(algo->len_tab - 1) / 2];
		algo->medians[0] = new_med;
		algo->curr_median_idx = 0;
		return ;
	}
	while (algo->tab_sorted[i] != algo->medians[algo->curr_median_idx])
		i++;
	new_med = algo->tab_sorted[i + ((algo->len_tab) - 1 - i) / 2];
	algo->medians[algo->curr_median_idx + 1] = new_med;
	(algo->curr_median_idx)++;
}

static void	ft_workona(t_stack **tab_stack, t_algo *algo, t_oper **oper)
{
	int	median;
	int	count_ra;

	count_ra = 0;
	median = algo->medians[algo->curr_median_idx];
	count_ra = ft_tools_workona(tab_stack, algo, oper);
	if (tab_stack[3]->nbr == median)
		ft_apply_operations(tab_stack, oper, "rrb");
	else if (ft_stacklen(tab_stack[2], 0) > 1
			&& tab_stack[2]->next->nbr > tab_stack[2]->nbr)
		ft_apply_operations(tab_stack, oper, "sb");
	if (algo->new_stacka_end)
	{
		while (count_ra)
		{
			ft_apply_operations(tab_stack, oper, "rra");
			count_ra--;
		}
	}
}

static void	ft_workonb(t_stack **tab_stack, t_algo *algo, t_oper **oper)
{
	int median;
	int count_rb;

	count_rb = 0;
	median = algo->medians[algo->curr_median_idx];
	count_rb = ft_tools_workonb(tab_stack, algo, oper);
	if (tab_stack[1]->nbr == median)
		ft_apply_operations(tab_stack, oper, "rra");
	else if (ft_stacklen(tab_stack[0], 0) > 1
			&& tab_stack[0]->next->nbr < tab_stack[0]->nbr)
		ft_apply_operations(tab_stack, oper, "sa");
	while (count_rb)
	{
		ft_apply_operations(tab_stack, oper, "rrb");
		count_rb--;
	}
}

void		ft_sorting_algo(t_stack **tab_stack, t_algo *algo, t_oper **oper)
{
	if (ft_is_sorted(tab_stack[0]) && !ft_stacklen(tab_stack[2], 0))
		return ;
	if (ft_stacklen(tab_stack[0], algo->new_stacka_end))
	{
		if (ft_stacklen(tab_stack[0], algo->new_stacka_end) <= 2)
			ft_sortmerge_stacka(tab_stack, algo, oper);
		else
		{
			algo->flag = 'a';
			ft_new_median(algo);
			ft_workona(tab_stack, algo, oper);
			ft_sorting_algo(tab_stack, algo, oper);
		}
	}
	if (ft_stacklen(tab_stack[2], 0) > 2)
	{
		algo->flag = 'b';
		ft_new_median(algo);
		ft_workonb(tab_stack, algo, oper);
		ft_sorting_algo(tab_stack, algo, oper);
	}
	else if (ft_stacklen(tab_stack[2], 0))
		ft_sortmerge_stacka(tab_stack, algo, oper);
}
