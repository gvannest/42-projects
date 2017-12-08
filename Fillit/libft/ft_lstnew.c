/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:09:29 by achirat           #+#    #+#             */
/*   Updated: 2017/11/17 16:20:40 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;
	void	*cont;

	if (!(cont = malloc(content_size)))
		return (0);
	if (!(link = (t_list*)malloc(sizeof(*link))))
		return (0);
	if (!content)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		link->content = ft_memcpy(cont, content, content_size);
		link->content_size = content_size;
	}
	link->next = NULL;
	return (link);
}
