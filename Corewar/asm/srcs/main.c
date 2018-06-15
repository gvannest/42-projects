/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:22:10 by msicot            #+#    #+#             */
/*   Updated: 2018/06/14 14:59:08 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_open(char *str)
{
	int fp;

	fp = 0;
	fp = open(str, O_RDONLY);
	if (fp < 0)
	{
		perror("Error");
		return(0);
	}
	return (fp);
}


int	main(int argc, char **argv)
{
	int fp;

	if (argc < 2 || argc > 2 || argv[1] == NULL)
		perror("Error");
	else if ((fp = ft_open(argv[1])) == 0)
		return (0);
	else
		ft_gnl(fp);
	return (0);
}
