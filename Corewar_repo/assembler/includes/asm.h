/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:53:35 by srossi            #+#    #+#             */
/*   Updated: 2018/08/29 11:38:09 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include "op.h"

typedef	struct		s_token
{
	int				type;
	char			*s_val;
	int				i_val;
	char			opcode;
	unsigned char	ocp;
	int				pos;
	int				last_op_pos;
	int				last_cor_index;
	int				line;
	int				cl;
	char			arg_size;
	char			nb_params;
	struct s_token	*next;
}					t_token;

typedef	struct		s_asm
{
	char			tab[CHAMP_MAX_SIZE];
	struct s_token	*atoken;
	char			comment[COMMENT_LENGTH + 1];
	char			name[PROG_NAME_LENGTH + 1];
	char			*code;
	char			*err_log;
	int				addon;
	int				comma_f;
	int				comment_f;
	int				comchr_f;
	int				directchr_f;
	int				end;
	int				error;
	int				err_pos;
	int				fp;
	int				fd_cor;
	int				gnl;
	int				label_f;
	int				line_nb;
	int				name_f;
	int				nb_comma;
	int				nb_param;
	int				nb_params;
	int				last_cor_index;
	int				last_opcode;
	int				last_op_pos;
	int				last_op_line;
	int				lock;
	char			f_option_h;
	char			f_option_d;
	int				operator_f;
	int				pos;
	int				quote;
	int				size;
	int				start;
	int				stop;
	char			cur_param;
	char			nb_params_left;
	char			*true_name;
	char			*path;
	int				nb_instr;
}					t_asm;

typedef	struct		s_op
{
	char			*name;
	int				nb_params;
	char			param_type[MAX_ARG];
	char			opcode;
	int				nb_cycles;
	char			*description;
	char			mod_carry;
	char			dir_oct_size;
}					t_op;

extern				t_op g_op_tab[NB_INSTR + 1];

/*
** PARSING:
*/
int					ft_is_sep(char c);
void				ft_gnl(t_asm *info);
int					ft_is_space(char c);
int					ft_is_othchr(char c);
char				*ft_type_char(int type);
int					ft_is_nonsep(char c, int f);
int					ft_is_comchar(int *num, char c);
int					ft_is_labelchar(int *ptr, char c);
void				retrieve_line(t_asm *info, char *line);
char				*retrieve_word(t_asm *info, char *line);
void				parse_correctly(t_asm *info, char *line);
void				analyse_separator(t_asm *info, char *line);
void				reset_words_flags(t_asm *info, char **arg);
int					ft_check_argv(t_asm *info, char **argv, int argc);
void				ft_check_options(t_asm *info, int argc, char **argv);
void				ft_toomuch_parsing(t_asm *info, char *line, int i);

/*
** ERRORS:
*/
void				ft_error_doubles(t_asm *info, int nb_error);
void				parsing_error(t_asm *info, char *line);
void				ft_error_length(t_asm *info, int nb_error);
void				command_name_error(t_asm *info, char *arg);
void				ft_error_management(t_asm *info, char *arg);
void				ft_error_incomplete(t_asm *info, int nb_error);
void				ft_error_param(t_asm *info, t_token *token, int nb_error);
void				error_instr(t_asm *info, char *arg);

/*
** LEXICAL ANALYSIS:
*/
int					ft_is_op(char *arg);
int					ft_is_reg(char *arg);
int					ft_is_dir(char *arg);
int					ft_is_ind(char *arg);
int					ft_is_label(char *arg);
int					ft_get_ival(char *arg);
int					ft_get_type(char *arg);
int					ft_get_opcode(char *arg);
void				ft_line_split(char *line);

/*
** FREE STRUCT:
*/
void				ft_free(t_asm *info);

/*
** TOKENS:
*/
void				ft_token_init(t_token *new_token);
void				ft_token_add(t_asm *sasm, char *arg);
void				ft_token_list_free(t_token *a_token);
void				ft_check_token(t_asm *info, t_token *token);
void				ft_token_reload(t_asm *info, t_token *token);
void				ft_token_load(t_asm *sasm, t_token *token, char *arg);
void				ft_token_load(t_asm *info, t_token *token, char *arg);
void				ft_token_add_tail(t_token **token, t_token *new_token);
void				ft_load_values_info(t_asm *info, char *arg, t_token *token);

/*
** CHAMPION FUNCTIONS:
*/
void				ft_display(t_asm *info);
int					ft_open_champ(char *path);
void				ft_create_champ(t_asm *info);
void				ft_option_display(t_asm *info);
void				ft_load_ocp(t_token *token_op);
void				ft_load_int(int nb, char *champ);
void				ft_load_short(short nb, char *champ);
void				ft_param_left(t_asm *info, t_token *p_token);
int					ft_param_op(t_asm *info, t_token *p_token, int index);
int					ft_param_dir(t_asm *info, t_token *p_token, int index);
int					ft_param_ind(t_asm *info, t_token *p_token, int index);
int					ft_param_reg(t_asm *info, t_token *p_token, int index);

/*
** FUNCTIONS RECHERCHE/REMPLISSAGE LABELS
*/
char				*ft_clean_label(char *label);
void				ft_fill_labels(t_token *atoken);
t_token				*ft_find_label(t_token *atoken, char *label);

/*
** FUNCTIONS ECRIRE SHORT OU INT DECOMPOSE EN OCTETS
*/
void				ft_write(t_asm *info);

/*
** FUNCTIONS SWAP BITS INT OU SHORT
*/
void				ft_swap_bytes_int(unsigned char *t);
void				ft_swap_bytes_short(unsigned char *t);

/*
** FUNCTION FIND INDEX DANS OPTAB
*/
int					ft_find_index_arg(char *arg);

/*
** USAGE / HELP FUNCTIONS:
*/
void				ft_help();
void				ft_print_usage(int argc, char **argv);

/*
** INIT STRUCT FUNCTION
*/
void				ft_init_info(t_asm *info);

#endif
