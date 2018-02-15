# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvannest <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 09:39:09 by gvannest          #+#    #+#              #
#    Updated: 2018/02/15 14:06:32 by gvannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = gvannest.filler

VPATH = src

SRC_NAME = main_filler.c ft_filler.c ft_display_fd.c

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

CPPFLAGS = -Iinclude -Ilibft/include
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft
LIBFT = libft.a

SRC = $(addprefix $(VPATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $^ -o $@ $(LIBFT_PATH)/$(LIBFT)

$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)
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
