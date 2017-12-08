/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:30:53 by achirat           #+#    #+#             */
/*   Updated: 2017/11/17 18:43:35 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	new = f(lst);
	start = new;
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		tmp->next = new;
		tmp = new;
		lst = lst->next;
	}
	tmp = NULL;
	new = start;
	return (new);
}
