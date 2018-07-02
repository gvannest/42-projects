/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 09:34:32 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/23 10:53:33 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *current;
	t_list *new;
	t_list *current_new;

	new = (*f)(lst);
	current = lst->next;
	current_new = new;
	if (lst == 0 || f == 0)
		return (0);
	while (current)
	{
		current_new->next = (*f)(current);
		current_new = current_new->next;
		current = current->next;
	}
	current_new->next = NULL;
	return (new);
}
