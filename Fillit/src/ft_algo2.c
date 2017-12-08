/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:15:51 by achirat           #+#    #+#             */
/*   Updated: 2017/11/30 10:49:16 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_remp(char **s, size_t k)
{
	size_t index;

	index = 0;
	if (s == NULL)
		return ;
	while (index < k)
	{
		(*s)[index] = '.';
		index++;
	}
}

static char		**ft_makegrille(char **grille, int k)
{
	int		j;

	j = 0;
	if (!(grille = (char**)malloc(sizeof(char*) * (k + 1))))
		exit(EXIT_FAILURE);
	while (j < k)
	{
		if (!(grille[j] = ft_strnew(k)))
		{
			j--;
			while (j >= 0)
			{
				free(grille[j]);
				j--;
			}
			exit(EXIT_FAILURE);
		}
		ft_remp(&(grille[j]), k);
		j++;
	}
	grille[j] = 0;
	return (grille);
}

char			**ft_algo2(size_t k, t_list *alst)
{
	char	**grille;
	int		j;
	t_list	*lst;

	lst = alst;
	grille = NULL;
	grille = ft_makegrille(grille, k);
	j = ft_strlen(grille[0]);
	if (ft_pos(grille, alst, k) == 0)
	{
		while (j > 0)
		{
			free(grille[j]);
			j--;
		}
		free(grille);
		return (ft_algo2(k + 1, alst));
	}
	return (grille);
}
