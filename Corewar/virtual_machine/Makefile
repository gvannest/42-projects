# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvannest <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 09:39:09 by gvannest          #+#    #+#              #
#    Updated: 2018/06/15 17:30:52 by gvannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

# COMPILATION
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ADDFLAGS = -g -fsanitize=address


# BINARY
NAME = corewar


# PATHS
VPATH = srcs
OBJ_PATH = obj
LIBFT_PATH = ../libft
INCLUDES_COR = ../includes
INCLUDES_LIBFT = ../libft/include


# SOURCES
SRC_NAME = main_corewar.c \
		   main_test.c

OBJ_NAME = $(SRC_NAME:.c=.o)


# PREFIXES
SRC = $(addprefix $(VPATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


# FLAGS
CPPFLAGS = -I$(INCLUDES_COR) -I$(INCLUDES_LIBFT)
LDFLAGS = -L$(LIBFT_PATH)
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

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $^ -o $@ $(LIBFT)

$(OBJ_PATH)/%.o: %.c $(INCLUDES_COR)/*.h $(LIBFT_PATH)/*.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	mkdir $@

clean:
	rm -rf $(OBJ_PATH)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all
