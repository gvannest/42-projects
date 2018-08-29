/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 17:13:06 by srossi            #+#    #+#             */
/*   Updated: 2018/08/02 16:06:29 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_help(void)
{
	ft_printf("NAME\n\t asm -- assemble a champion\n\n");
	ft_printf("SYNOPSIS\n\t asm [-h | -d] [file ...]\n\n");
	ft_printf("DESCRIPTION\n\t For one file of a type \".s\", written with\
the language \'assembly\', the progam translate the file into\
machine code which will be read by our Virtual Machine.\n\n");
	ft_printf("\tThe following options are available:\n\n");
	ft_printf("\t-h\tPrint a help message and exit.\n\n");
	ft_printf("\t-d\tDisplay the champion in machine language if correct.\n\n");
	exit(EXIT_SUCCESS);
}
