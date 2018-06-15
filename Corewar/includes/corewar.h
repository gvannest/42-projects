/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:52:06 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/15 18:26:23 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"

# include "test_unitaire.h"


typedef struct		s_player // Structure d'un joueur
{
	char			*pyr_name; // nom du joueur
	int				pyr_nbr;	// numero du joueur
	int				nb_instruction; // nombre d'instructions envoyees par le joueur
	unsigned int	pyr_nb_live; // Nombre de "live" execute sur ce numero de joueur
}					t_player;

typedef struct		s_arena // Structure de l'arene = structure principale
{
	char			arena[MEM_SIZE]; // Tableau de char representant l'arene (memoire)
	int				arena_pyr[MEM_SIZE]; // Meme tableau avec int = num joueur. couleur = par num de joueur
	unsigned int	nb_cycle;// nombre de cycles depuis le debut du jeu
	unsigned int	nb_processus; // nombre de processus en vie
	int				last_live_pyr; // dernier joueur a avoir dit "live"
	t_player		player1; // structure du joueur 1
	t_player		player2; // structure du joueur 2
	struct s_proc	*list_proc; // pointeur vers debut liste chainee des processus
}					t_arena;

typedef struct		s_proc
{
	int				pyr_from; // joueur qui a cree le processus
	int				reg[REG_NUMBER]; // tableau des registres (16 registres par defaut attention r1 et non r0
	int				pc_act; // Registre PC = contient l'adresse courante du processus (index dans arena)
	int				pc_next; // adresse de l'instruction suivante
	int				nb_live_proc; // nombre de processus en vie
	int				nb_live_cycle; // nombre de vie executees par le processus dans le cycle actuel
	char			carry; // flag de carry : passe a 1 si l'instruction donne 0 pour certaines ope uniquement
	struct s_proc	*parent; // pointeur vers le processus parent. le fils garde les proprietes du parent sauaf adresse
	struct s_proc	*son; // pointeur vers fils
	struct s_proc	*next; // pointeur vers next
}					t_proc;


#endif



