# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvannest <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 09:39:09 by gvannest          #+#    #+#              #
#    Updated: 2018/02/12 16:58:59 by gvannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libftprintf.a

VPATH = src

SRC_NAME = ft_printf.c ft_buffer.c ft_control_flags.c \
		   ft_clean_flags.c ft_cast_arg.c ft_typed.c ft_typeu.c \
		   ft_types.c ft_typec.c ft_reinit_struct.c ft_typeo.c ft_typex.c \
		   ft_typep.c ft_typepercent.c ft_type_unicodec.c ft_wcharconv.c \
		   ft_type_unicodes.c ft_typeb.c ft_couleur.c

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

CPPFLAGS = -I./include

LIBFT_PATH = ./Libft

CFLAGS = -Wall -Wextra -Werror

SRC = $(addprefix $(VPATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIB) 
	make -C $(LIBFT_PATH)
	ar rc $@ $^
	ranlib $@

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
