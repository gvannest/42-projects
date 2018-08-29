/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:33:38 by msicot            #+#    #+#             */
/*   Updated: 2018/08/28 16:56:52 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_print_champ(t_arena *arena)
{
	int			i;
	t_player	*tmp;

	i = 0;
	while (i < arena->nb_pyrs)
	{
		tmp = &arena->tab_pyr[i];
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				tmp->pyr_nbr, tmp->nb_inst, tmp->pyr_name, tmp->comment);
		++i;
	}
}

void		ft_dump_mem(t_arena *arena)
{
	int	i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	ft_print_champ(arena);
	ft_printf("0x%#04x : ", i);
	while (i < MEM_SIZE)
	{
		if (i % 32 == 0 && i != 0)
			ft_printf("%#0.4x : ", i);
		ft_printf("%.2hhx ", arena->map[i]);
		++i;
		if (i % 32 == 0)
			ft_printf("\n");
	}
	ft_free_listproc(arena->list_proc);
}

int			ft_dump(t_arena *arena, char **argv, int argc, int i)
{
	if (i + 1 >= argc)
		return (0);
	if (ft_isnum(argv[i + 1]))
	{
		arena->dump_f = 1;
		arena->dump_nb = ft_atoi(argv[i + 1]);
		if (arena->dump_nb < 0)
		{
			ft_error_vm(8, "-d must be followed by UNSIGNED INT", NULL, 0);
			exit(0);
		}
		return (1);
	}
	else
		ft_error_vm(8, "-d must be followed by UNSIGNED INT", NULL, 0);
	return (0);
}
