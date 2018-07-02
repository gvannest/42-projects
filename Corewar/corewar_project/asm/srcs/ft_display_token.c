/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 14:13:05 by srossi            #+#    #+#             */
/*   Updated: 2018/06/26 14:39:09 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_display_token(t_token *token)
{
	ft_printf("TOKEN\n");
	ft_printf("    Type : %s\n", token->type);
	ft_printf("    Valeur (str) : %s\n", token->s_val);
	ft_printf("    Valeur (int) : %d\n", token->i_val);
	ft_printf("    Position : %d\n", token->pos);
	ft_printf("    Line numero : %d\n", token->line);
	ft_printf("    Colonne numero : %d\n", token->cl);
}
