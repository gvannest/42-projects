/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:12:33 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/03 15:12:35 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/checker.h"

void        ft_check_dup(int new_nbr, t_stack **tab_stack, char **ptr_argv)
{
    t_stack *tmp;

    tmp = tab_stack[0];
    while (tmp)
    {
        if (tmp->nbr == new_nbr)
            ft_errors(0, ptr_argv, 0, tab_stack);
        tmp = tmp->next;
    }
}

void        ft_add_input(char *argv_i, t_stack **tab_stack)
{
    int     j;
    int     i;
    int     new_nbr;
    char    **ptr_argv;
    t_stack *new_stacka;

    j = 0;
    ptr_argv = ft_strsplit(argv_i, ' ');
    while (ptr_argv[j])
    {
        i = 0;
        while (ptr_argv[j][i])
        {
            if (!ft_isdigit(ptr_argv[j][i]))
                ft_errors(0, ptr_argv, 0, tab_stack);
            i++;
        }
        new_nbr = ft_atoi(ptr_argv[j]);
        ft_check_dup(new_nbr, tab_stack, ptr_argv);
        new_stacka = ft_stacknew(new_nbr);
        ft_add_stackend(new_stacka, &tab_stack[0], &tab_stack[1]);
        j++;
    }
    ft_clear_all(0, ptr_argv, 0, 0);
}

