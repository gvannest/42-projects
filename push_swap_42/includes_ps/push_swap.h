/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:20:28 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/03 14:20:30 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "checker.h"

typedef struct  s_algo
{
    char        *ope;
    char        flag;
    t_stack     *current_pivot;
    int         *tab_sorted;
}               t_algo;

void            ft_algorithm(t_stack **tab_stack);
char            *ft_choose_operation(t_stack **tab_stack, t_algo *algo);
void            ft_sort_tab(t_stack *stack_a, t_algo *algo);


#endif
