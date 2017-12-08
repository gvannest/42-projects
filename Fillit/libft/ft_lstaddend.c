/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:02:01 by achirat           #+#    #+#             */
/*   Updated: 2017/11/20 09:32:44 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list *lst, t_list *new)
{
	t_list	*tmp;

	tmp = lst;
	if (!lst || !new)
		return ;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}
