/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:53:35 by srossi            #+#    #+#             */
/*   Updated: 2018/06/14 14:14:33 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
# include "../../libft/inc/libft.h"
# include "../../libft/inc/libftprintf.h"
# include "../../libft/inc/get_next_line.h"
void	ft_error(int a);
void	ft_gnl(int fp);
/*
typedef struct s_label
{
	char 	*name;
	struct	*s_instruction;
	int		address;

}

typedef struct s_asm
{
	char 	*tab;
	struct 	*label;
}			  t_asm;

*/
#endif
