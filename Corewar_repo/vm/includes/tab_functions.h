/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:45:28 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/26 14:51:49 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_FUNCTIONS_H
# define TAB_FUNCTIONS_H

# include "corewar.h"

typedef struct				s_functions
{
	char	o;
	void	(*f_inst)(t_arena*, t_proc*);
}							t_functions;

t_functions					g_tab_function[] =
{
	{1, &ft_live},
	{2, &ft_load},
	{3, &ft_store},
	{4, &ft_add},
	{5, &ft_sub},
	{6, &ft_and},
	{7, &ft_or},
	{8, &ft_xor},
	{9, &ft_zjmp},
	{10, &ft_ldi},
	{11, &ft_sti},
	{12, &ft_fork},
	{13, &ft_lld},
	{14, &ft_lldi},
	{15, &ft_lfork},
	{16, &ft_aff},
};

#endif
