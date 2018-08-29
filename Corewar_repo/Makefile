
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msicot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 09:42:10 by msicot            #+#    #+#              #
#    Updated: 2018/08/29 11:58:32 by srossi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEPS = Makefile vm/Makefile assembler/Makefile
LIBS = ./libft/

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

# RULES

.PHONY: all
all: $(DEPS)
	@$(MAKE) -C vm/
	@$(MAKE) -C assembler/

.PHONY: clean
clean:
	@$(MAKE) clean -C vm/
	@$(MAKE) clean -C assembler/
	@$(MAKE) clean -C $(LIBS)

.PHONY: fclean
fclean:
	@$(MAKE) fclean -C vm/
	@$(MAKE) fclean -C assembler/
	@$(MAKE) fclean -C $(LIBS)

.PHONY: re
re:
	@$(MAKE) fclean
	@$(MAKE) all
