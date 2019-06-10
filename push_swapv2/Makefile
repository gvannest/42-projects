# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvannest <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/03 14:13:27 by gvannest          #+#    #+#              #
#    Updated: 2019/05/03 14:13:31 by gvannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PATHS
CHECKER_PATH = ./checker_files/
PUSH_SWAP_PATH = ./push_swap_files/


.PHONY: all
all: checkercomp pushswapcomp Makefile

checkercomp:
	@make all -C $(CHECKER_PATH)

pushswapcomp:
	@make all -C $(PUSH_SWAP_PATH)

.PHONY: clean
clean:
	@make clean -C $(CHECKER_PATH)
	@make clean -C $(PUSH_SWAP_PATH)

.PHONY: fclean
fclean: clean
	@make fclean -C $(CHECKER_PATH)
	@make fclean -C $(PUSH_SWAP_PATH)

.PHONY: re
re: fclean all