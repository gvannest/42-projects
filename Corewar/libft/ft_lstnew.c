/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:13:37 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/22 11:54:41 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*cont;
	size_t	cont_size;

	cont_size = content_size;
	if (!(cont = malloc(sizeof(*cont) * content_size)))
		return (0);
	if (!(list = (t_list*)malloc(sizeof(*list))))
		return (0);
	if (content == 0)
	{
		list->content = 0;
		list->content_size = 0;
	}
	else
	{
		list->content = ft_memcpy(cont, content, content_size);
		list->content_size = cont_size;
	}
	list->next = NULL;
	return (list);
}
