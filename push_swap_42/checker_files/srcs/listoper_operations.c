/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:44:35 by gvannest          #+#    #+#             */
/*   Updated: 2019/05/31 19:52:29 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_ps/checker.h"

t_oper		*ft_opernew(char *line)
{
	t_oper	*list;

	if (!(list = (t_oper*)malloc(sizeof(*list))))
		return (0);
	list->instruction = line;
	list->next = NULL;
	return (list);
}

void		ft_add_oper(t_oper *new, t_oper **oper_start)
{
	t_oper	*list;

	list = *oper_start;
	if (oper_start == 0 || new == 0)
		return ;
	if (*oper_start == 0)
		*oper_start = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}
