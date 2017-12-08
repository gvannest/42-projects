/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:36:20 by achirat           #+#    #+#             */
/*   Updated: 2017/11/30 10:49:29 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			ft_cancel(char **grille, int i, int j, t_list *alst)
{
	int	x1;
	int	y1;
	int	a;

	a = 0;
	while (a < 4)
	{
		x1 = j + CONTENT->X[a];
		y1 = i + CONTENT->Y[a];
		grille[y1][x1] = '.';
		a++;
	}
}

static int			ft_check_pos(char **grille, int i, int j, t_list *alst)
{
	int	x1;
	int	y1;
	int	a;
	int	k;

	a = 0;
	k = ft_strlen(grille[0]);
	while (a < 4)
	{
		x1 = j + CONTENT->X[a];
		y1 = i + CONTENT->Y[a];
		if (x1 > k - 1 || y1 > k - 1 || x1 < 0 || grille[y1][x1] != '.')
			return (0);
		a++;
	}
	a = 0;
	while (a < 4)
	{
		x1 = j + CONTENT->X[a];
		y1 = i + CONTENT->Y[a];
		grille[y1][x1] = CONTENT->lettre;
		a++;
	}
	return (1);
}

int					ft_pos(char **grille, t_list *alst, int k)
{
	int	i;
	int	j;

	i = 0;
	if (alst == NULL)
		return (1);
	while (grille[i] != 0)
	{
		j = 0;
		while (grille[i][j])
		{
			if (grille[i][j] == '.')
				if (ft_check_pos(grille, i, j, alst))
				{
					if (ft_pos(grille, alst->next, k))
						return (1);
					else
						ft_cancel(grille, i, j, alst);
				}
			j++;
		}
		i++;
	}
	return (0);
}
