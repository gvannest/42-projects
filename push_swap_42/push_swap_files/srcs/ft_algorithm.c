/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:00:03 by gvannest          #+#    #+#             */
/*   Updated: 2019/06/01 13:32:18 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/push_swap.h"
#include "../../includes_ps/tabptrope.h"

int			ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;
	int		prev;
	int		curr;

	prev = 0;
	curr = 0;
	if (ft_stacklen(stack, 0) == 1)
		return (1);
	if (stack)
	{
		prev = stack->nbr;
		tmp = stack->next;
		while (tmp)
		{
			curr = tmp->nbr;
			if (curr < prev)
				return (0);
			prev = curr;
			tmp = tmp->next;
		}
	}
	return (1);
}

void		ft_apply_operations(t_stack **tab_stack, t_oper **oper, char *ope)
{
	int		i;

	i = 0;
	while (i < SIZE_OPE)
	{
		if (!ft_strcmp(ope, tabope[i].ope))
			tabope[i].ft_ps_ope(tab_stack, oper);
		i++;
	}
}

static void	ft_calc_minmax(int *min, int *max, t_stack **tab_stack)
{
	t_stack *tmp_stack;

	*min = tab_stack[0]->nbr;
	*max = tab_stack[0]->nbr;
	tmp_stack = tab_stack[0];
	while (tmp_stack)
	{
		if (tmp_stack->nbr < *min)
			*min = tmp_stack->nbr;
		if (tmp_stack->nbr > *max)
			*max = tmp_stack->nbr;
		tmp_stack = tmp_stack->next;
	}
}

static void	ft_algo_short(t_stack **tab_stack, t_oper **oper)
{
	int min;
	int max;

	ft_calc_minmax(&min, &max, tab_stack);
	while (!ft_is_sorted(tab_stack[0]))
	{
		if (tab_stack[0]->nbr == min)
		{
			ft_apply_operations(tab_stack, oper, "pb");
			ft_apply_operations(tab_stack, oper, "sa");
			ft_apply_operations(tab_stack, oper, "pa");
		}
		if (tab_stack[0]->nbr == max)
			ft_apply_operations(tab_stack, oper, "ra");
		if (tab_stack[0]->next->nbr < tab_stack[0]->nbr)
			ft_apply_operations(tab_stack, oper, "sa");
	}
}

void		ft_algorithm(t_stack **tab_stack, t_oper **oper)
{
	t_algo	algo;
	int		len;

	algo.flag = 0;
	len = ft_stacklen(tab_stack[0], 0);
	if (!(algo.tab_sorted = (int*)malloc(sizeof(int) * len)))
		exit(EXIT_FAILURE);
	ft_bzero(algo.tab_sorted, sizeof(int) * ft_stacklen(tab_stack[0], 0));
	ft_sort_tab(tab_stack[0], &algo);
	if (!(algo.medians = (int*)ft_memalloc(sizeof(int) * algo.len_tab)))
		exit(EXIT_FAILURE);
	algo.curr_median_idx = -1;
	algo.new_stacka_end = NULL;
	if (len == 3)
		ft_algo_short(tab_stack, oper);
	else
		ft_sorting_algo(tab_stack, &algo, oper);
	free(algo.tab_sorted);
	free(algo.medians);
}
