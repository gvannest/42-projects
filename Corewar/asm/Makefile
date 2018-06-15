# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msicot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 09:42:10 by msicot            #+#    #+#              #
#    Updated: 2018/06/14 16:34:36 by srossi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c ft_error.c ft_parsing.c

ROOT = $(shell pwd)/

PRGS = $(ROOT)/asm/

all :
	@sh init.sh
	@for dir in $(PRGS) ; \
		do \
		$(MAKE) -C $$dir; \
		done
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/

clean :
	@for dir in $(PRGS) ; \
		do \
		$(MAKE) $@ -C $$dir; \
		done

fclean :
	@for dir in $(PRGS) ; \
		do \
		$(MAKE) $@ -C $$dir; \
		done
	@sh uninit.sh

re :
	@$(MAKE) fclean
	@$(MAKE) all

prog :
	@$(MAKE) $(ROOT)/asm
