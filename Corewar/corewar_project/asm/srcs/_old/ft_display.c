/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:30:10 by srossi            #+#    #+#             */
/*   Updated: 2018/06/19 14:23:48 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void ft_display_param(t_param *param, int param_id)
{
	ft_printf("Parametre %d :\n     Type : %s (%i)\n     Value : %s (%b)\n     Label : %i\n", param_id, param->type_name, param->type, param->str_value, param->int_value, param->f_label);	
}

void	ft_display_instruction(t_instruction *instruction)
{
	ft_printf("Instruction :\n  Nom : %s\n  OCP : %c\n  Opcode : %c\n", instruction->name, instruction->ocp, instruction->opcode);
	ft_display_param(&instruction->param1, 1);
	ft_display_param(&instruction->param2, 2);
	ft_display_param(&instruction->param3, 3);
}

void	ft_display_label(t_label *label)
{
	ft_printf("Label :\n Nom : %s\n", label->name);
	ft_display_instruction(label->instruction);
}

void	ft_display_asm(t_asm *sasm)
{
	int i;

	i = 0;
	if (sasm != NULL)
	{
		ft_printf("ASM :\n");
		while (sasm->tab && sasm->tab[i])
		{
			ft_printf("$c ", sasm->tab[i]);
			i++;
		}
		if (sasm->label != NULL)
			ft_display_label(sasm->label);
	}
}
