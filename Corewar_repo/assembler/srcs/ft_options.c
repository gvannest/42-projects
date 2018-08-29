/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:10:23 by srossi            #+#    #+#             */
/*   Updated: 2018/08/02 11:03:08 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_option_display(t_asm *info)
{
	ft_display(info);
	ft_free(info);
	exit(EXIT_SUCCESS);
}

static	int		ft_is_option(char c)
{
	int index;
	int is_option;

	index = 0;
	is_option = 0;
	while (ASM_OPTION_CHARS[index])
	{
		if (ASM_OPTION_CHARS[index] == c)
		{
			is_option = 1;
			break ;
		}
		index++;
	}
	return (is_option);
}

static	void	ft_set_option(t_asm *info, char option)
{
	if (option == 'h')
		info->f_option_h = 1;
	else if (option == 'd')
		info->f_option_d = 1;
}

static	int		ft_options_valid(t_asm *info, char *arg)
{
	int	index;
	int	is_valid;

	index = 1;
	is_valid = 0;
	if (arg == NULL || ft_strlen(arg) < 2 || arg[0] != '-')
		return (is_valid);
	is_valid = 1;
	while (arg[index])
	{
		if (!ft_is_option(arg[index]))
		{
			is_valid = 0;
			break ;
		}
		else
			ft_set_option(info, arg[index]);
		index++;
	}
	return (is_valid);
}

void			ft_check_options(t_asm *info, int argc, char **argv)
{
	if (!ft_options_valid(info, argv[1])
			|| (info->f_option_h && info->f_option_d))
		ft_print_usage(argc, argv);
	else if (info->f_option_h)
		ft_help();
}
