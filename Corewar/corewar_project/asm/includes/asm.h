/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:53:35 by srossi            #+#    #+#             */
/*   Updated: 2018/06/20 18:11:44 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_param
{
	char	type;
	char	*type_name;
	int		int_value;
	char	*str_value;
	char	f_label;
}				t_param;

typedef struct	s_instruction
{
	char	*name;
	char	ocp;
	char	opcode;
	struct	s_param	param1;
	struct	s_param	param2;
	struct	s_param	param3;
	struct	s_instruction *next_instruction;
}				t_instruction;

typedef struct s_label
{
	char 	*name;
	struct	s_instruction *instruction;
	int		address;
	struct	s_label	*next_label; 

}			t_label;

typedef struct s_asm
{
	char 	*tab;
	struct 	s_label *label;
}			  t_asm;


void	ft_error(int a);
void	ft_gnl(int fp);
void	ft_display_param(t_param *param, int param_id);
void	ft_display_instruction(t_instruction *instruction);
void	ft_display_label(t_label *label);
void	ft_display_asm(t_asm *sasm);
void	ft_label_add_tail(t_asm *sasm, t_label *new_label);
void	ft_label_new(t_asm *sasm, char *label_name);
void	ft_label_free(t_label *label);
void	ft_label_add_instruction(t_label *label, t_instruction *new_instruction);
void	ft_instruction_new(t_label *label, char *label_name);
void	ft_instruction_free(t_instruction *instruction);
void	ft_instruction_free_all(t_label *label);
void	ft_param_free(t_param *param);
void	ft_split_line(t_asm *sasm, char *line);


#endif
