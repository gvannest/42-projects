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

void            ft_algorithm(t_stack **tab_stack);
char            *ft_choose_operation(t_stack **tab_stack, char *b_emp);
void            ft_clear_seen(t_stack *stack_a);


#endif
