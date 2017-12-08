# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achirat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 09:12:44 by achirat           #+#    #+#              #
#    Updated: 2017/12/05 17:08:13 by achirat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c ft_read2.c ft_algo2.c ft_fill.c ft_fill_lst.c

OBJS = $(SRCS:.c=.o)

VPATH = SRCS:./src OBJS:./obj

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/ re
	$(CC)  $(OBJS) ./libft/libft.a -o $(NAME) 

.PHONY: clean fclean all re 

clean: 
	@rm -rf $(OBJS)
	@make -C libft/ clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all
