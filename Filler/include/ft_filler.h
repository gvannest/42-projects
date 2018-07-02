/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:59:26 by gvannest          #+#    #+#             */
/*   Updated: 2018/03/07 15:45:58 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft.h"

# define SHAPE_ME game->shape_me
# define SHAPE_OP game->shape_op
# define COUNT_OP game->count_op
# define WIN_FILLER game->win_filler
# define BOARDL game->board_nbln
# define BOARDC game->board_nbcol
# define BOARD game->board
# define MAP_OP game->map_op
# define MAP_ME game->map_me
# define MAPOME game->mapome
# define MAP_SCORE game->map_score
# define PIECE_NBLN game->piece_nbln
# define PIECE_NBCOL game->piece_nbcol
# define PIECE game->piece
# define COOR_LN game->coor_ln
# define COOR_CL game->coor_cl
# define TURN_1 game->turn_1
# define TURN_2 game->turn_2
# define PIECE_LNCOUNT game->piece_lncount
# define ABS(X) (X < 0 ? -X : X)
# define SEUIL 15

typedef struct		s_filler
{
	char	shape_me;
	char	shape_op;
	char	win_filler;
	int		count_op;
	int		board_nbln;
	int		board_nbcol;
	char	*board;
	double	*map_op;
	double	*map_me;
	double	*mapome;
	double	*map_score;
	int		piece_nbln;
	int		piece_nbcol;
	int		piece_lncount;
	char	*piece;
	int		coor_cl;
	int		coor_ln;
	int		turn_1;
	int		turn_2;
}					t_filler;

void				ft_filler(t_filler *game);
int					ft_getinfo(t_filler *game, char **line);
void				ft_small_maps(t_filler *game, int k);
int					ft_validspot(t_filler *game, int i);
void				ft_big_map(t_filler *game, char c, double *tmp);
void				ft_algofiller(t_filler *game);
int					ft_influence(t_filler *game);

#endif
