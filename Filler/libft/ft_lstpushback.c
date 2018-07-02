/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:13:10 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/24 19:39:39 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **list, t_list *new)
{
	t_list *current;

	if (list == 0 || new == 0)
		return ;
	current = *list;
	while (current->next)
		current = current->next;
	current->next = new;
	new->next = NULL;
}
