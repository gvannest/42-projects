# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvannest <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/03 14:13:27 by gvannest          #+#    #+#              #
#    Updated: 2019/06/01 13:46:58 by gvannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ADDFLAGS =

# DEFAULT RULE
DEFRULE = all

# BINARY
NAME = push_swap

# PATHS
SRC_PATH = ./srcs/
SRC_PATH_CH = ../checker_files/srcs/
OBJ_PATH = ./objs/
OBJ_PATH_CH = ./objs/
LIBFT_PATH = ../libft/
INC_PATH = ../includes_ps\
    ../libft/includes/ \

# SOURCES
SRC_NAME = \
    push_swap.c \
    ft_algorithm.c \
    ft_quicksort_stack.c \
    ft_sort_tab.c \
    ft_sortmerge.c \
	ft_tools_algo.c

SRC_NAME_CH = \
    ft_parse_checker.c \
    ft_push.c \
    ft_revrot.c \
    ft_rotate.c \
    ft_swap.c \
    liststack_operations.c \
    listoper_operations.c \
    ft_clear_error.c \
    ft_check_sort.c \
    ft_print_stack.c \



OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME_CH = $(SRC_NAME_CH:.c=.o)


# PREFIXES
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
SRC_CH = $(addprefix $(SRC_PATH_CH),$(SRC_NAME_CH))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_CH = $(addprefix $(OBJ_PATH_CH),$(OBJ_NAME_CH))

# FLAGS
CPPFLAGS = -I./includes/ -I../libft/includes
LDFLAGS = -L../libft/
LFT = -lft
LIBFT = $(LDFLAGS) $(LFT)

# **************************************************************************** #
# SPECIAL CHARS

LOG_CLEAR= \033[2K
LOG_UP= \033[A
LOG_NOCOLOR= \033[0m
LOG_BOLD= \033[1m
LOG_UNDERLINE= \033[4m
LOG_BLINKING= \033[5m
LOG_BLACK= \033[1;30m
LOG_RED= \033[1;31m
LOG_GREEN= \033[1;32m
LOG_YELLOW= \033[1;33m
LOG_BLUE= \033[1;34m
LOG_MAGENTA= \033[1;35m
LOG_CYAN= \033[1;36m
LOG_WHITE= \033[1;37m
LOG_ORANGE= \033[1;38;5;208m

# **************************************************************************** #

# RULES

# MAIN RULES
default:
	@make $(DEFRULE)

.PHONY: all
all: libftcomp $(OBJ_PATH) $(NAME) Makefile

libftcomp:
	@make all -C $(LIBFT_PATH)

$(NAME): $(OBJ) $(OBJ_CH)
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)....................... $(LOG_ORANGE)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(ADD_FLAGS) $(LIBFT) $(OBJ) $(OBJ_CH) -o $@
	@mv $(NAME) ..
	@echo -e "--$(LOG_CLEAR)$(LOG_CYAN)$(NAME)$(LOG_NOCOLOR) compiled................. $(LOG_GREEN)✓$(LOG_NOCOLOR)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(ADDFLAGS) -c -o $@ $<

$(OBJ_PATH_CH)%.o: $(SRC_PATH_CH)%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(ADDFLAGS) -c -o $@ $<

$(OBJ_PATH):
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"
	@mkdir -p $(OBJ_PATH)

.PHONY: clean
clean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deleted.............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJ_PATH)

.PHONY: fclean
fclean: clean
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean $(NAME)$(LOG_NOCOLOR)"
	@rm -f ../$(NAME)

.PHONY: re
re: fclean all
