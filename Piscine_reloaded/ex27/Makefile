# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvannest <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 17:17:14 by gvannest          #+#    #+#              #
#    Updated: 2017/11/08 17:37:09 by gvannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRC = ft_display_file.c
FLAGS = -Wall -Wextra -Werror
OBJ = ft_display_file.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L. -lft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
