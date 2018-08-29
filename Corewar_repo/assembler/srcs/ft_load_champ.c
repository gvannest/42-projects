/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:18:39 by srossi            #+#    #+#             */
/*   Updated: 2018/08/03 16:33:08 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_load_ocp(t_token *token_op)
{
	t_token	*p_token;
	int		params_nb;
	int		index;

	p_token = token_op->next;
	params_nb = token_op->nb_params;
	index = 6;
	while (index >= 6 / params_nb)
	{
		if (p_token->type == T_DIR_LAB)
			token_op->ocp = token_op->ocp | (2 << index);
		else if (p_token->type == T_IND_LAB || p_token->type == T_IND)
			token_op->ocp = token_op->ocp | (3 << index);
		else
			token_op->ocp = token_op->ocp | (p_token->type << index);
		index -= 2;
		p_token = p_token->next;
	}
}

void	ft_load_int(int nb, char *champ)
{
	unsigned char	octets[4];
	int				index;

	index = 0;
	octets[0] = nb >> 0;
	octets[1] = nb >> 8;
	octets[2] = nb >> 16;
	octets[3] = nb >> 24;
	ft_swap_bytes_int(octets);
	while (index < 4)
	{
		champ[index] = octets[index];
		index++;
	}
}

void	ft_load_short(short nb, char *champ)
{
	unsigned char	octets[2];
	unsigned char	tmp;
	int				index;

	index = 0;
	octets[0] = nb >> 0;
	octets[1] = nb >> 8;
	tmp = octets[0];
	ft_swap_bytes_short(octets);
	champ[0] = octets[0];
	champ[1] = octets[1];
}
