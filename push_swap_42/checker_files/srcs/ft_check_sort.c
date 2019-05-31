/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:19:56 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/31 20:06:14 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/checker.h"

void		ft_check_sort(t_stack **tab_stack)
{
	t_stack	*tmp;
	int		prev;
	int		curr;

	prev = tab_stack[0]->nbr;
	tmp = tab_stack[0]->next;
	if (ft_stacklen(tab_stack[2], 0))
		ft_printf("KO\n");
	else if (ft_stacklen(tab_stack[0], 0) == 1)
		ft_printf("OK\n");
	else
	{
		while (tmp)
		{
			curr = tmp->nbr;
			if (curr < prev)
			{
				ft_printf("KO\n");
				return ;
			}
			prev = curr;
			tmp = tmp->next;
		}
		ft_printf("OK\n");
	}
}
