/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:26:39 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/24 20:27:04 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list *l1;
	t_list *l2;
	t_list *l3;

	if (!(*alst)->next)
		return ;
	l1 = *alst;
	l2 = l1->next;
	l3 = l2->next;
	l1->next = NULL;
	l2->next = l1;
	while (l3)
	{
		l1 = l2;
		l2 = l3;
		l3 = l3->next;
		l2->next = l1;
	}
	*alst = l2;
}
