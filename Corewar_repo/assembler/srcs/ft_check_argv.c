/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:21:48 by msicot            #+#    #+#             */
/*   Updated: 2018/08/02 16:04:03 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	usage_err(char *path, int i)
{
	if (i == 1)
		ft_printf("Can't read source file %s\n", path);
	exit(1);
}

static void	check_name(t_asm *info, char *path)
{
	int i;
	int	j;
	int k;

	if (path == NULL)
		return ;
	i = (int)ft_strlen(path) - 1;
	j = i;
	k = 0;
	while (i >= 0 && path[i])
	{
		if (path[i] == '/')
		{
			info->path = ft_strsub(path, 0, i + 1);
			break ;
		}
		if (info->comma_f == 0)
			++k;
		if (path[i] == '.')
			info->comma_f = 1;
		--i;
	}
	info->true_name = ft_strsub(path, i + 1, j - i - k);
}

static int	ft_open(t_asm *info, char *path)
{
	int	fp;

	fp = 0;
	fp = open(path, O_RDONLY);
	if (fp < 0)
		usage_err(path, 1);
	info->fp = fp;
	if (fp >= 0)
		check_name(info, path);
	return (fp);
}

void		ft_print_usage(int argc, char **argv)
{
	if (argc < 2)
		ft_printf("Usage: %s <sourcefile.s>\n", argv[0]);
	else if (argc > 2)
		ft_printf("Usage: %s [-h | -d] <sourcefile.s>\n", argv[0]);
	exit(1);
}

int			ft_check_argv(t_asm *info, char **argv, int argc)
{
	if (argc < 2 || argc > 3)
		ft_print_usage(argc, argv);
	if (argc == 3)
	{
		ft_check_options(info, argc, argv);
		info->fp = ft_open(info, argv[2]);
	}
	else
		info->fp = ft_open(info, argv[1]);
	return (info->fp);
}
