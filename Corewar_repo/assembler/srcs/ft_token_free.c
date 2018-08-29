/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:20:10 by srossi            #+#    #+#             */
/*   Updated: 2018/07/06 10:20:19 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_token_free(t_token *token)
{
	if (token == NULL)
		return ;
	if (token->s_val != NULL)
		ft_strdel(&token->s_val);
	free(token);
}

void	ft_token_list_free(t_token *a_token)
{
	t_token *p_token;

	p_token = a_token;
	if (p_token == NULL)
		return ;
	while (p_token)
	{
		a_token = a_token->next;
		ft_token_free(p_token);
		p_token = a_token;
	}
}
