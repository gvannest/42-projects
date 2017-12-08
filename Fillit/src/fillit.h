/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:46:45 by achirat           #+#    #+#             */
/*   Updated: 2017/11/30 10:49:05 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFF_SIZE 21
# define CONTENT ((t_tetra*)(alst->content))
# define X tab[0]
# define Y tab[1]

typedef struct	s_tetra
{
	char	*str_dom;
	int		tab[2][4];
	char	lettre;
}				t_tetra;

t_list			*ft_read(char *av, size_t *ret);
char			**ft_algo2(size_t ret, t_list *alst);
int				ft_pos(char **grille, t_list *alst, int k);
void			ft_stock(char *str, t_list **alst, char let);

#endif
