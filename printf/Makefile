# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvannest <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 09:39:09 by gvannest          #+#    #+#              #
#    Updated: 2017/12/22 14:21:15 by gvannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = printf.out

SRC_PATH = src
SRC_NAME = ft_printf.c printf_main.c ft_lecture.c 

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
 
CPPFLAGS = -I./include -I./Libft

LDFLAGS = -L./Libft -fsanitize=address
LDLIBS = -lft

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C Libft/
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	mkdir $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)




