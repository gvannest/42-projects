/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:29:11 by srossi            #+#    #+#             */
/*   Updated: 2018/06/19 18:17:02 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_label_add_tail(t_asm *sasm, t_label *new_label)
{
	t_label *p_label;
	
	p_label = sasm->label;
	if (new_label != NULL)
	{
		if (sasm->label == NULL)
			sasm->label = new_label;
		else
		{
			while (p_label->next_label != NULL)
				p_label = p_label->next_label;
			p_label->next_label = new_label;
		}
		new_label->next_label = NULL;
	}
}

void	ft_label_new(t_asm *sasm, char *label_name)
{
	t_label new_label;
	
	new_label.name = ft_strdup(label_name); //ne pas oublier de la free
	new_label.instruction = NULL; //modifier quand ajout instruction
	new_label.address = 0; //modifier quand ?
	new_label.next_label = NULL;
	ft_label_add_tail(sasm, &new_label);
}

void	ft_label_free(t_label *label)
{
	ft_strdel(&label->name);
	ft_instruction_free_all(label);
	free(label);
}
