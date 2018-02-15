/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:59:26 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/15 13:29:01 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H 
# define FT_FILLER_H
# include "libft.h"

# define PIECE game->piece

typedef struct		s_filler
{
	char	piece;
}					t_filler;

void	ft_filler(t_filler *game);
void	ft_display_fd(t_filler *game);



#endif
