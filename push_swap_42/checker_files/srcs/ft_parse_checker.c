/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:12:33 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/31 20:12:47 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/checker.h"

void		ft_check_dup(int new_nbr, t_stack **tab_stack, char **ptr_argv)
{
	t_stack	*tmp;

	tmp = tab_stack[0];
	while (tmp)
	{
		if (tmp->nbr == new_nbr)
			ft_errors(0, ptr_argv, 0, tab_stack);
		tmp = tmp->next;
	}
}

int			ft_check_argvj(char *argvj)
{
	int	i;

	i = 0;
	while (argvj[i])
	{
		if (argvj[0] == '-' || argvj[0] == '+')
			i++;
		else
		{
			if (!ft_isdigit(argvj[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

void		ft_add_input(char *argv_i, t_stack **tab_stack)
{
	int		j;
	int		new_nbr;
	char	**ptr_argv;
	t_stack	*new_stacka;

	j = 0;
	ptr_argv = ft_strsplit(argv_i, ' ');
	if (!ptr_argv[j])
		ft_errors(0, ptr_argv, 0, tab_stack);
	while (ptr_argv[j])
	{
		if (!ft_check_argvj(ptr_argv[j]))
			ft_errors(0, ptr_argv, 0, tab_stack);
		new_nbr = ft_atoi_int(ptr_argv[j]);
		if (!new_nbr && ft_strcmp(ptr_argv[j], "0"))
			ft_errors(0, ptr_argv, 0, tab_stack);
		ft_check_dup(new_nbr, tab_stack, ptr_argv);
		new_stacka = ft_stacknew(new_nbr);
		ft_add_stackend(new_stacka, &tab_stack[0], &tab_stack[1]);
		j++;
	}
	ft_clear_all(0, ptr_argv, 0, 0);
}
