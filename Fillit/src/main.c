/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 09:53:33 by achirat           #+#    #+#             */
/*   Updated: 2017/11/30 10:50:03 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t		ft_ret(int ret)
{
	if (ret % 21 != 20)
	{
		ft_putendl("error");
		exit(0);
	}
	return (ft_nextsqrt((ret / 21 + 1) * 4));
}

int					main(int argc, char **argv)
{
	t_list	*a;
	size_t	ret;
	char	**grille;
	size_t	i;

	ret = 0;
	i = 0;
	if (argc == 2)
	{
		a = ft_read(argv[1], &ret);
		grille = ft_algo2(ft_ret(ret), a);
		while (grille[i])
		{
			ft_putstr(grille[i]);
			ft_putchar('\n');
			i++;
		}
	}
	else
	{
		ft_putendl("usage: ./fillit source_file");
	}
	return (0);
}
