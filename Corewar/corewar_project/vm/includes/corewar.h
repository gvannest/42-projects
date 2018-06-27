/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:52:06 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/27 14:54:13 by gvannest         ###   ########.fr       */
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
#include <ncurses.h>

# include "test_unitaire.h"


typedef struct		s_player // Structure d'un joueur
{
	char			pyr_name[PROG_NAME_LENGTH + 1]; // nom du joueur
	int				pyr_nbr;	// numero du joueur
	int				nb_inst; // nombre d'instructions envoyees par le joueur
	char			champ[CHAMP_MAX_SIZE + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	pyr_nb_live; // Nombre de "live" execute sur ce numero de joueur
}					t_player;

typedef struct		s_arena // Structure de l'arene = structure principale
{
	char			map[MEM_SIZE + 1]; // Tableau de char representant l'arene (memoire)
	int				map_pyr[MEM_SIZE]; // Meme tableau avec int = num joueur. couleur = par num de joueur
	int				map_process[MEM_SIZE]; // Meme tableau avec int = num processus
	unsigned int	nb_cycle;// nombre de cycles depuis le debut du jeu
	unsigned int	nb_processus; // nombre de processus en vie
	unsigned short	nb_pyrs; // nb de joueurs
	int				last_live_pyr; // dernier joueur a avoir dit "live"
	t_player		tab_pyr[MAX_PLAYERS]; // tableau de structures de joueur a trier en fonction des -n
	struct s_proc	*list_proc; // pointeur vers debut liste chainee des processus
}					t_arena;

typedef struct		s_proc
{
	int				pyr_from; // joueur qui a cree le processus
	int				reg[REG_NUMBER]; // tableau des registres (16 registres par defaut attention r1 et non r0
	short int		pc_act; // Registre PC = contient l'adresse courante du processus (index dans arena)
	short int		pc_next; // adresse de l'instruction suivante
	int				nb_live_proc; // nombre de processus en vie
	int				nb_live_cycle; // nombre de vie executees par le processus dans le cycle actuel
	char			carry; // flag de carry : passe a 1 si l'instruction donne 0 pour certaines ope uniquement
	struct s_proc	*parent; // pointeur vers le processus parent. le fils garde les proprietes du parent sauaf adresse
	struct s_proc	*son; // pointeur vers fils
	struct s_proc	*next; // pointeur vers next
}					t_proc;


void				ft_error_vm(char code, char *msg1, char *msg2, int v1);
unsigned long long	ft_convert_nbr(char *str, size_t k);
void				ft_parse_vm1(char *line, t_arena *arena, char *cor, int i);
void				ft_parse_vm2(char *line, t_arena *arena, char *cor, int i);
void				ft_param(int argc, char **argv, t_arena *arena);
void				ft_assert(char *line, t_arena *arena);
int					ft_isnum(char *str);
void				ft_fill_game(t_arena *arena);

#endif



