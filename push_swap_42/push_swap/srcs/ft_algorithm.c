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


static int      ft_check_sort_2(t_stack **tab_stack)
{
    t_stack *tmp;
    int     prev;
    int     curr;

    prev = 0;
    curr = 0;
    if (ft_stacklen(tab_stack[2]))
        return (0);
    if (ft_stacklen(tab_stack[0]) == 1)
        return (1);
    if (tab_stack[0])
    {
        prev = tab_stack[0]->nbr;
        tmp = tab_stack[0]->next;
        while (tmp) {
            curr = tmp->nbr;
            if (curr < prev)
                return (0);
            prev = curr;
            tmp = tmp->next;
        }
    }
    return (1);
}

static void     ft_apply_operations(t_stack **tab_stack, char *ope)
{
int i;

    i = 0;
    while (i < SIZE_OPE)
    {
        if (!ft_strcmp(ope, tabope[i].ope))
            tabope[i].ft_ps_ope(tab_stack);
        i++;
    }
}
//
//char            *ft_check_shorter(char *ope, char *prev_ope)
//{
//    if ((!ft_strcmp(ope, "sa") && !ft_strcmp(prev_ope, "sb"))
//    || (!ft_strcmp(prev_ope, "sa") && !ft_strcmp(ope, "sb")))
//        return (ft_strcpy(ft_strnew(4), "ss"));
//
//    if ((!ft_strcmp(ope, "ra") && !ft_strcmp(prev_ope, "rb"))
//        || (!ft_strcmp(prev_ope, "ra") && !ft_strcmp(ope, "rb")))
//        return (ft_strcpy(ft_strnew(4), "rr"));
//
//    if ((!ft_strcmp(ope, "rra") && !ft_strcmp(prev_ope, "rrb"))
//        || (!ft_strcmp(prev_ope, "rra") && !ft_strcmp(ope, "rrb")))
//        return (ft_strcpy(ft_strnew(4), "rrr"));
//
//    return (ope);
//}

void            ft_algorithm(t_stack **tab_stack)
{
    char    *ope;
//    char    *prev_ope;
    char    b_emp;
//    char    ch;

    b_emp = 0;
//    prev_ope = 0;
    while (!ft_check_sort_2(tab_stack))
    {
//        scanf("%c", &ch);
//        if (ch == ' ')
//        {
            ope = ft_choose_operation(tab_stack, &b_emp);
            //Cette partie ci desosus ne fonctionne pas car prev ope a deja etait effectuée. a changer
//            ope = prev_ope ? ft_check_shorter(ope, prev_ope) : ope;
            ft_printf("%s\n", ope);
            ft_apply_operations(tab_stack, ope);
//            prev_ope ? ft_strdel(&prev_ope) : 0;
//            prev_ope = ft_strcpy(ft_strnew(4), ope);
            ft_strdel(&ope);
//            ft_printf("======================\n");
//            ft_printf("Stack_A after : \n");
//            ft_print_stacks(tab_stack[0]);
//            ft_printf("======================\n");
//            ft_printf("Stack_B after: \n");
//            ft_print_stacks(tab_stack[2]);

//        }
//        ft_strdel(&prev_ope);
    }
}
