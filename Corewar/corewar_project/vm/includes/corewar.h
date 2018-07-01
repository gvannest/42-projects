/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:52:06 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/29 18:12:46 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "get_next_line.h"
# include "corewar_visual.h"

# include "test_unitaire.h"


typedef struct		s_player
{
	char			pyr_name[PROG_NAME_LENGTH + 1];
	int				pyr_nbr;
	int				nb_inst;
	char			champ[CHAMP_MAX_SIZE + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	pyr_nb_live;
}					t_player;

typedef struct		s_arena
{
	char			map[MEM_SIZE + 1];
	int				map_pyr[MEM_SIZE];
	int				map_process[MEM_SIZE];
	unsigned int	nb_cycle;
	unsigned int	nb_live_proc;
	unsigned short	nb_pyrs;
	int				last_live_pyr;
	t_player		tab_pyr[MAX_PLAYERS];
	struct s_proc	*list_proc;
}					t_arena;

typedef struct		s_proc
{
	int				p_nbr;
	int				reg[REG_NUMBER];
	int				pc_act;
	short int		pc_next;
	int				nb_live_cycle;
	char			carry;
	struct s_proc	*parent;
	struct s_proc	*son;
	struct s_proc	*next;
}					t_proc;

typedef struct s_op
{  
	char	*name;
	int		nb_params;
	char	param_type[MAX_ARG];
	int 	opcode;
	int		nb_cycles;
	char	*description;
	int 	mod_carry;
	int		dir_oct_size; //0 = 4 octets et 1 = 2 octets
}				t_op;

extern t_op op_tab[NB_INSTR + 1];

void				ft_error_vm(char code, char *msg1, char *msg2, int v1);
unsigned long long	ft_convert_nbr(char *str, size_t k);
void				ft_parse_vm1(char *line, t_arena *arena, char *cor, int i);
void				ft_parse_vm2(char *line, t_arena *arena, char *cor, int i);
void				ft_param(int argc, char **argv, t_arena *arena);
void				ft_assert(char *line, t_arena *arena);
int					ft_isnum(char *str);
void				ft_fill_game(t_arena *arena);
void				ft_init_process(t_arena *arena);
void				ft_visual(t_arena *arena);

#endif



