# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvannest <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 09:39:09 by gvannest          #+#    #+#              #
#    Updated: 2018/03/07 16:20:43 by gvannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = gvannest.filler

VPATH = src

SRC_NAME = main_filler.c ft_getinfo.c ft_validspot.c \
		   ft_algofiller.c ft_influence.c ft_small_maps.c \
		   ft_big_map.c

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

INCLUDES = include
INCLUDES_FILES = ft_filler.h

LIBFT_PATH = ./libft
LIBFT = libft.a

CPPFLAGS = -I$(INCLUDES) -I$(LIBFT_PATH)/$(INCLUDES)
CFLAGS = -Wall -Wextra -Werror

SRC = $(addprefix $(VPATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $^ -o $@ $(LIBFT_PATH)/$(LIBFT)

$(OBJ_PATH)/%.o: %.c $(INCLUDES)/$(INCLUDES_FILES) $(LIBFT_PATH)/*.c | $(OBJ_PATH)
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
