# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srossi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 16:02:59 by srossi            #+#    #+#              #
#    Updated: 2018/06/14 16:03:35 by srossi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT = $(shell pwd)/

.PHONY: all clean fclean re

ifeq ($(LIB_NEED),)
	LIB_NEED = './libft'
endif

all :
	@for dir in $(LIB_NEED) ; \
		do \
		$(MAKE) -C $(ROOT)$$dir; \
		done

clean :
	@for dir in $(LIB_NEED) ; \
		do \
		$(MAKE) $@ -C $(ROOT)$$dir; \
		done

fclean :
	@for dir in $(LIB_NEED) ; \
		do \
		$(MAKE) $@ -C $(ROOT)$$dir; \
		done

re :
	$(MAKE) fclean
	$(MAKE) all
