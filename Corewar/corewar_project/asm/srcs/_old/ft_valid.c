/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:02:27 by srossi            #+#    #+#             */
/*   Updated: 2018/06/21 16:32:00 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"


static int	ft_check_nb_params(char **tab, char **tab_params)
{
	int tab_size;
	int	nb_params;
	extern t_op op_tab[NB_INSTR + 1];
	int opcode;
	int inst_name;

	opcode = 0;
	tab_size = ft_strtab_nblines(tab);
	nb_params = ft_strtab_nblines(tab_params) - 1;
	inst_name_pos = ((tab_size == 3)? 1 : 0);
	
	while (opcode < NB_INSTR)
	{
		if (ft_strcmp(op_tab[opcode].name, tab[inst_name_pos]) == 0)
		{
			if (op_tab[opcode].nb_params == nb_params)
				return (1);
		}
		opcode++;
	}
	return (0);
}

// checker les nobres comme "01" ou "0000002"

int	ft_is_reg(char *argument)
{
	int index;
	argument_ln = ft_strlen(argument);

	index = 0;
	if (argument_ln == 0 || argument[index++] != 'r' || ft_atoi(argument) >= REG_NUMBER)
		return (0);
	while (index < argument_ln)
	{ 
		if (!ft_isdigit(argument[index]))
			return (0);
		index++;
	}
	return (1);
}

int	ft_is_valid_line(char **tab, char **tab_params)
{
	if (!ft_check_nb_params(tab, tab_params))
			return (0);
		
	return (1);
}
