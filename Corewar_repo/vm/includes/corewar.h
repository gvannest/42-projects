/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:52:06 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/28 16:55:45 by gvannest         ###   ########.fr       */
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

typedef struct		s_player
{
	char			pyr_name[PROG_NAME_LENGTH + 1];
	int				pyr_nbr;
	int				nb_inst;
	int				color_pyr;
	char			champ[CHAMP_MAX_SIZE + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	pyr_nb_live;
}					t_player;

typedef struct		s_arena
{
	char			map[MEM_SIZE + 1];
	int				map_pyr[MEM_SIZE];
	int				map_process[MEM_SIZE];
	int				nb_cycle;
	int				nb_cycle_current;
	int				cycle_to_die;
	unsigned int	nb_live_currt;
	unsigned int	nb_live_tot;
	int				nb_live_proc;
	unsigned int	nb_round_no_decrease;
	char			dump_f;
	int				dump_nb;
	int				nb_pyrs;
	int				last_live_pyr;
	t_player		tab_pyr[MAX_PLAYERS];
	float			cycle_sec;
	struct s_proc	*list_proc;
}					t_arena;

typedef struct		s_param
{
	int				value;
	char			size;
	char			type;
}					t_param;

typedef struct		s_proc
{
	short int		p_nbr;
	int				reg[REG_NUMBER];
	short int		pc_act;
	char			opcode_act;
	char			opcode_valid;
	unsigned int	nb_cycle_before_op;
	char			flag_live;
	char			carry;
	char			jump;
	char			ocp;
	char			ocp_valid;
	t_param			tab_param[3];
	struct s_proc	*next;
}					t_proc;

typedef struct		s_op
{
	char			*name;
	int				nb_params;
	char			param_type[MAX_ARG];
	char			opcode;
	int				nb_cycles;
	char			*description;
	int				mod_carry;
	int				dir_oct_size;
}					t_op;

extern t_op g_optab[NB_INSTR + 1];

void				ft_error_vm(char code, char *msg1, char *msg2, int v1);
void				ft_parse_vm1(char *line, t_arena *arena, char *cor, int i);
void				ft_parse_vm2(char *line, t_arena *arena, char *cor, int i);
char				ft_arguments(int argc, char **argv, t_arena *arena);
void				ft_sort_pyr(t_arena *arena);
void				ft_assert(char *line, t_arena *arena);
int					ft_isnum(char *str);
void				ft_fill_game(t_arena *arena);
void				ft_init_process(t_arena *arena);
void				ft_create_proc(t_arena *arena, t_proc *proc, short index);
WINDOW				*create_newwin(int height, int width, int starty,
					int startx);
void				ft_visual(t_arena *arena, t_corvisu *visual);
void				ft_init_visual(t_corvisu *visual);
void				ft_is_proc(t_corvisu *visual, int pyr_idx, char inst,
					int i);
void				ft_is_not_proc(t_corvisu *visual, int pyr_idx, char inst,
					int i);
void				ft_info_game(t_arena *arena, t_corvisu *visual);
void				ft_infogame_fix(t_arena *arena, t_corvisu *visual, char *f);
void				ft_info_player(t_arena *arena, t_corvisu *visual);
void				ft_winner_visu(t_player *tab_pyr, int nb_pyrs,
					t_corvisu *visual, int last_live_pyr);
void				ft_game(t_arena *arena, t_corvisu *visual, char v);
void				ft_check_cycle(t_arena *arena);
t_proc				*ft_kill_process(t_proc **begin_list, t_proc *proc_to_kill);
void				ft_reinit_cycle(t_arena *arena, t_proc *proc);
void				ft_reinit_param(t_proc *proc);
void				ft_next_opcode(t_arena *arena, t_proc *proc);
void				ft_one_cycle(t_arena *arena, t_proc *proc);
void				ft_move_process(int *map_process, t_proc *proc, char ocp);
int					ft_get_param(t_arena *arena, t_proc *proc, int pc,
					char dir_size);
int					ft_dump(t_arena *arena, char **argv, int argc, int i);
void				ft_dump_mem(t_arena *arena);

void				ft_live(t_arena *arena, t_proc *proc);
void				ft_load(t_arena *arena, t_proc *proc);
void				ft_store(t_arena *arena, t_proc *proc);
void				ft_add(t_arena *arena, t_proc *proc);
void				ft_sub(t_arena *arena, t_proc *proc);
void				ft_and(t_arena *arena, t_proc *proc);
void				ft_or(t_arena *arena, t_proc *proc);
void				ft_xor(t_arena *arena, t_proc *proc);
void				ft_zjmp(t_arena *arena, t_proc *proc);
void				ft_ldi(t_arena *arena, t_proc *proc);
void				ft_sti(t_arena *arena, t_proc *proc);
void				ft_fork(t_arena *arena, t_proc *proc);
void				ft_lld(t_arena *arena, t_proc *proc);
void				ft_lldi(t_arena *arena, t_proc *proc);
void				ft_lfork(t_arena *arena, t_proc *proc);
void				ft_aff(t_arena *arena, t_proc *proc);

unsigned long		ft_read_memory(char *map, int start, size_t k);
void				ft_write_memory(char *map, unsigned int v, int start,
					size_t k);
void				ft_update_map_pyr(int *map_pyr, int pc_act, int start,
					size_t k);
void				ft_calc_index(int *k, int value, int pc_act, char flag_idx);

void				ft_free_listproc(t_proc *begin_list);

void				ft_print_test(char *line);

#endif
