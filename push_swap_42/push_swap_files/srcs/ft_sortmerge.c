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

void    ft_sortmerge_stacka(t_stack **tab_stack, t_algo *algo, t_oper **oper)
{
    int i;
    char b1;
    char b2;

    i = 0;
    b1 = (ft_stacklen(tab_stack[0], 0) > 1 && tab_stack[0]->next->nbr < tab_stack[0]->nbr);
    b2 = (ft_stacklen(tab_stack[2], 0) > 1 && tab_stack[2]->next->nbr > tab_stack[2]->nbr);
    if (b1)
        ft_apply_operations(tab_stack, oper, "sa");
    else if (b2)
        ft_apply_operations(tab_stack, oper, "sb");
    if (algo->curr_median_idx < 1) //une seule median ou aucune soit que 4 nb sur a initialement
    {
        while (ft_stacklen(tab_stack[2], 0))
            ft_apply_operations(tab_stack, oper, "pa");
    }
    else
    {
        while (tab_stack[2]->nbr >= algo->medians[algo->curr_median_idx - 1]) // je push ceux superieurs a la moyenne precedente (la moyenne actuelle est au dessus du tas
            ft_apply_operations(tab_stack, oper, "pa");
        algo->curr_median_idx -= 2;
        while (algo->tab_sorted[i] != algo->medians[algo->curr_median_idx + 1])
            i++;
        algo->len_tab = i;
        algo->new_stacka_end = tab_stack[0];
    }

}
