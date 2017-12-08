/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:48:50 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/30 10:49:40 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_relative_coor(t_tetra *domino)
{
	int		k;
	int		x0;
	int		y0;

	k = 0;
	x0 = domino->X[0];
	y0 = domino->Y[0];
	while (k < 4)
	{
		domino->X[k] = domino->X[k] - x0;
		domino->Y[k] = domino->Y[k] - y0;
		k++;
	}
}

void			ft_stock(char *str, t_list **alst, char let)
{
	t_tetra	*domino;
	t_list	*lst;
	size_t	a;
	size_t	y;

	y = 0;
	a = 0;
	if (!(domino = (t_tetra*)malloc(sizeof(*domino))))
		exit(0);
	domino->str_dom = str;
	while (str[a])
	{
		if (str[a] == '#')
		{
			domino->X[y] = a % 5;
			domino->Y[y] = a / 5;
			y++;
		}
		a++;
	}
	domino->lettre = let;
	ft_relative_coor(domino);
	if (!(lst = ft_lstnew(domino, sizeof(*domino))))
		exit(0);
	ft_lstadd(alst, lst);
}
