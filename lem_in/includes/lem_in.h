/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:52:39 by srossi            #+#    #+#             */
/*   Updated: 2018/05/03 09:28:53 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct					s_ant
{
	int				nb;
	int				*path;
	int				nb_moves;
	int				wave;
	struct s_ant	*next;
}								t_ant;

typedef struct					s_room
{
	char			*name;
	int				nb_room;
	int				x;
	int				y;
	struct s_link	*next_map;
	struct s_room	*next;
}								t_room;

typedef struct					s_link
{
	t_room			*room;
	struct s_link	*next;
}								t_link;

typedef struct					s_line
{
	char			*str;
	struct s_line	*next;
}								t_line;

typedef struct					s_set
{
	int			**set;
	int			nb_path;
	int			cost;
	short		found;
}								t_set;

typedef struct					s_game
{
	t_ant			*ants;
	t_room			*rooms;
	t_room			*room_start;
	t_room			*room_end;
	t_set			set;
	t_line			*lines;
	int				f_start;
	int				flag;
	int				f_error;
	int				f_end;
	int				k;
	int				f_section;
	int				nb_rooms;
	int				nb_ants;
	int				n;
	int				limit;
}								t_game;

typedef struct					s_paths
{
	t_room			*room;
	struct s_paths	*next;
}								t_paths;

typedef struct					s_ways
{
	t_room			**sh_path;
	int				*way;
	struct s_ways	*next;
}								t_ways;

typedef struct					s_pile
{
	t_room			**path;
	struct s_pile	*next;
}								t_pile;

void							ft_select_path(t_game *game);
void							ft_display_res(t_game *game);
int								ft_parse(char *line, t_game *game);
int								ft_create_bounds(t_game *game, char *line);
int								ft_create_room(t_game *game, char *line);
int								ft_sizepath(int *path);
void							ft_compatibilities(t_game *game, t_ways **start,
								int n);
int								ft_display_lst(t_room *room);
int								ft_is_start(char *line);
void							ft_give_path_cost(t_game *game, int **set,
								int n, int ants);
int								ft_is_end(char *line);
t_ways							*ft_short_path(t_game *game);
int								ft_new_shortpath(t_game *game, t_pile *current,
								t_ways **list_ways);
void							ft_print_set(int **set, int n);
int								ft_is_com(char *line);
int								ft_is_tube(char *line);
int								ft_is_room(char *line);
int								ft_add_lants(t_game *game);
int								ft_add_line(char *line, t_game *game);
int								ft_last_check(t_game *game);
int								ft_display_lines(t_game *game);
void							ft_init_set(t_game *game);
int								ft_error(char *reason);
int								ft_free_ants(t_game *game, t_ant *aants);
int								ft_free_rooms(t_room *aroom);
int								ft_free_links(t_link *alink);
int								ft_free_lines(t_line *aline);
int								ft_free_listways(t_ways *list_ways);

#endif
