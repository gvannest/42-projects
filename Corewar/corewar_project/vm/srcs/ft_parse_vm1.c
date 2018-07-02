/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_vm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:55:30 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/29 15:05:17 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_check_magic(char *line, char *cor)
{
	int magic;

	magic = (int)(ft_convert_nbr(line, 4));
	if (magic != COREWAR_EXEC_MAGIC)
		ft_error_vm(2, "Error : Wrong magic number", cor, magic);
}

static void		ft_get_name(char *line, t_arena *arena, char *cor, int i)
{
	int	j;

	j = 0;
	while (j < PROG_NAME_LENGTH + 1)
	{
		arena->tab_pyr[i].pyr_name[j] = line[j];
		j++;
	}
	if (line[j])
		ft_error_vm(4, "Error : champion's name is too long", cor, 1);
}

static void		ft_nb_instruct(char *line, t_arena *arena, int i, char *cor)
{
	int nb;

	nb = (int)(ft_convert_nbr(line, 4));
	if (nb > CHAMP_MAX_SIZE || nb < 1)
		ft_error_vm(5, "Error : Wrong champion size", cor, nb);
	arena->tab_pyr[i].nb_inst = nb;
}

static void		ft_check_transition(char *line, char *cor, int p)
{
	int a;

	a = 0;
	while (a < 4)
	{
		if (line[a])
			ft_error_vm(6, "Error : wrong transition format", cor, p);
		a++;
	}
}

void			ft_parse_vm1(char *line, t_arena *arena, char *cor, int i)
{
	ft_check_magic(line, cor);
	ft_get_name(line + 4, arena, cor, i);
	ft_check_transition(line + 4 + PROG_NAME_LENGTH, cor, 1);
	ft_nb_instruct(line + 2 * 4 + PROG_NAME_LENGTH, arena, i, cor);
	ft_check_transition(line + HEADER_SIZE, cor, 2);
	ft_parse_vm2(line, arena, cor, i);
}

