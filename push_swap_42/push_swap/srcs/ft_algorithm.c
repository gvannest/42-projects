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
# include "../../includes_ps/tabptrope.h"


//static int      ft_check_sort_2(t_stack **tab_stack)
//{
//    t_stack *tmp;
//    int     prev;
//    int     curr;
//
//    prev = 0;
//    curr = 0;
//    if (ft_stacklen(tab_stack[2]))
//        return (0);
//    if (ft_stacklen(tab_stack[0]) == 1)
//        return (1);
//    if (tab_stack[0])
//    {
//        prev = tab_stack[0]->nbr;
//        tmp = tab_stack[0]->next;
//        while (tmp) {
//            curr = tmp->nbr;
//            if (curr < prev)
//                return (0);
//            prev = curr;
//            tmp = tmp->next;
//        }
//    }
//    return (1);
//}

//static void     ft_apply_operations(t_stack **tab_stack, char *ope)
//{
//int i;
//
//    i = 0;
//    while (i < SIZE_OPE)
//    {
//        if (!ft_strcmp(ope, tabope[i].ope))
//            tabope[i].ft_ps_ope(tab_stack);
//        i++;
//    }
//}

void            ft_algorithm(t_stack **tab_stack)
{
    t_algo  algo;
    int i = 0;
//    char    ch;

    algo.flag = 0;
    algo.current_pivot = 0;
    if(!(algo.tab_sorted = (int*)malloc(sizeof(int) * ft_stacklen(tab_stack[0]))))
        exit(EXIT_FAILURE);
    ft_sort_tab(tab_stack[0], &algo);
    while (i < ft_stacklen(tab_stack[0]))
        ft_printf("%d ", algo.tab_sorted[i++]);
//    while (!ft_check_sort_2(tab_stack))
//    {
//        scanf("%c", &ch);
//        if (ch == ' ')
//        {
//            algo.ope = ft_choose_operation(tab_stack, &algo);
//            ft_printf("%s\n", algo.ope);
//            ft_apply_operations(tab_stack, algo.ope);
//            ft_strdel(&ope);
//            ft_printf("======================\n");
//            ft_printf("Stack_A after : \n");
//            ft_print_stacks(tab_stack[0]);
//            ft_printf("======================\n");
//            ft_printf("Stack_B after: \n");
//            ft_print_stacks(tab_stack[2]);

//        }
//    }
}
