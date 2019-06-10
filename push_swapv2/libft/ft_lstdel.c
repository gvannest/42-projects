/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:08:59 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/22 13:26:26 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *list1;
	t_list *list2;

	list1 = *alst;
	if (alst == 0)
		return ;
	while (list1)
	{
		list2 = list1;
		(*del)(list1->content, list1->content_size);
		list1 = list1->next;
		free(list2);
	}
	*alst = NULL;
}
