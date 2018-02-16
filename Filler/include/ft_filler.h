/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:59:26 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/16 18:22:28 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H 
# define FT_FILLER_H
# include "libft.h"

# define FORME game->forme
# define BOARD_NBLN game->board_nbln
# define BOARD_NBCOL game->board_nbcol
# define BOARD game->board
# define PIECE_NBLN game->piece_nbln
# define PIECE_NBCOL game->piece_nbcol
# define PIECE game->piece

typedef struct		s_filler
{
	char	forme;
	int		board_nbln;
	int		board_nbcol;
	char	**board;
	int		piece_nbln;
	int		piece_nbcol;
	int		*tab[2]
	char	**piece;
	int		fd;
}					t_filler;

void	ft_filler(t_filler *game);
void	ft_getinfo(t_filler *game, char **line);
void	ft_display_fd(t_filler *game);
void	ft_filler(t_filler *game);



#endif
