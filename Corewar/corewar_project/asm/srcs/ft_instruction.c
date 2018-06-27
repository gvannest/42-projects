/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:36:23 by srossi            #+#    #+#             */
/*   Updated: 2018/06/19 18:17:02 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_instruction_add_tail(t_label *label, t_instruction *new_instruction)
{
	t_instruction *p_instruction;
	
	p_instruction = label->instruction;
	if (new_instruction != NULL)
	{
		if (label->instruction == NULL)
			label->instruction = new_instruction;
		else
		{
			while (p_instruction->next_instruction != NULL)
				p_instruction = p_instruction->next_instruction;
			p_instruction->next_instruction = new_instruction;
		}
		new_instruction->next_instruction = NULL;
	}
}

void	ft_instruction_new(t_label *label, char *line)
{
	t_instruction new_instruction;
	
	char *instruction_name = line;

	new_instruction.name = ft_strdup(instruction_name); //ne pas oublier de la free
	//new_instruction.ocp = NULL;
	//new_instruction.opcode = NULL;
	//new_instruction.param1 = ft_fill_param();
	//new_instruction.param2 = ft_fill_param();
	//new_instruction.param3 = ft_fill_param();
	new_instruction.next_instruction = NULL;
	ft_instruction_add_tail(label, &new_instruction);
}

void	ft_instruction_free(t_instruction *instruction)
{
	ft_strdel(&instruction->name);
	free(instruction);
}

void	ft_instruction_free_all(t_label *label)
{
	t_instruction *p_instruction;

	p_instruction = label->instruction;
	ft_strdel(&p_instruction->name);
	while (p_instruction->next_instruction)
	{
		label->instruction = p_instruction->next_instruction;
		ft_instruction_free(p_instruction);
		p_instruction = label->instruction;
	}
	free(p_instruction);
}
