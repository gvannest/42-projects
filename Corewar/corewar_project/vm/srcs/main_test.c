/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:43:33 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/29 17:16:21 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*static void	ft_print_cor(char *line)
{
	int i = 0;

	printf(" ");
	while (i < COR_SIZE_MAX + 5)
	{
		printf("%.2hhx", line[i]);
		i++;
		if (i % 16 == 0 & i != 0)
			printf("\n");
		if (i % 2 == 0)
			printf(" ");
	}
	putchar('\n');
	putchar('\n');
}

static void		ft_print_champ(t_arena *arena)
{
	unsigned short i;
	int k;

	i = 0;
	while(i < (arena->nb_pyrs))
	{
		k = 0;
		//printf("%d /", arena->tab_pyr[i].pyr_nbr);
		//printf("%s /", arena->tab_pyr[i].pyr_name);
		//printf("%s /", arena->tab_pyr[i].comment);
		//printf("%#x / %d/ ", arena->tab_pyr[i].nb_instructions, arena->tab_pyr[i].nb_instructions);
		while (k < arena->tab_pyr[i].nb_inst)
		{
			printf("%.2hhx ", arena->tab_pyr[i].champ[k]);
			k++;
			if (k % 16 == 0)
				printf("\n");
		}
		printf("\n\n");
		i++;
	}
}
*/

/*void		ft_print_map(t_arena *arena)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i != 0 && i % 64 == 0)
			printf("\n");
		printf("%.2hhx ", arena->map[i]);
		i++;
	}
	printf("\n");
	printf("\n");
}

void		ft_print_map_pyr(t_arena *arena)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i != 0 && i % 64 == 0)
			printf("\n");
		printf("%.2d ", arena->map_pyr[i]);
		i++;
	}
	printf("\n");
	printf("\n");
}

void		ft_print_map_proc(t_arena *arena)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i != 0 && i % 64 == 0)
			printf("\n");
		printf("%.2d ", arena->map_process[i]);
		i++;
	}
	printf("\n");
	printf("\n");
}
*/
void		ft_print_registres(t_arena *arena)
{
	t_proc *ptr;
	int		i;

	ptr = arena->list_proc;
	while (ptr)
	{
		i = 1;
		printf("Registres %d : [%d, ", ptr->p_nbr, ptr->reg[0]);
		while (i < REG_NUMBER - 1)
		{
			printf("%d, ", ptr->reg[i]);
			i++;
		}
		printf("%d]\n", ptr->reg[i]);
		ptr = ptr->next;
	}
}

void		ft_assert(char *line, t_arena *arena)
{
	(void)line;
	//ft_print_cor(line);
	//ft_print_champ(arena);
	//ft_print_map(arena);
	//ft_print_map_pyr(arena);
	//ft_print_map_proc(arena);
	ft_print_registres(arena);
}

