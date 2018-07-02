/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:13:46 by srossi            #+#    #+#             */
/*   Updated: 2018/06/21 16:32:00 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"


void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_split_line(t_asm *sasm, char *line)
{
	char **tab;
	char **tab_params;
	int size_tab;

	size_tab = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[size_tab])
		size_tab++;
	tab_params = ft_strsplit(tab[size_tab - 1], ',');
	if (ft_is_valid_line(tab, tab_params))
	{
		(void) sasm;
	//	ft_load_asm(sasm, tab);
	//	ft_load_asm(sasm, tab_params);
	}
	ft_free_tab(tab);
	ft_free_tab(tab_params);
}
