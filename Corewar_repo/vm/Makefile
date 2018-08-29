# COMPILATION
CC = gcc
FLAGS = -Wall -Wextra -Werror -g

#BINARY
NAME = corewar
DST = ./

# OPTIONS
DEBUG = no
ifeq ($(DEBUG), yes)
	FLAGS += -g -fsanitize=address
endif

NOFLAGS = no
ifeq ($(NOFLAGS), yes)
	FLAGS = -g -w
endif

# PATHS
LIBS = ../libft/libft.a
LIB_PATH = ../libft
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
LIB_NCURSES = -lncurses

# SOURCES
SRC_NAME = ft_arguments.c \
		   ft_dump.c \
		   ft_check_cycle.c \
		   ft_error_vm.c \
		   ft_fill_game.c \
		   ft_free_corewar.c \
		   ft_game.c \
		   ft_create_processus.c \
		   ft_live.c \
		   ft_ld_and_lld.c \
		   ft_add.c \
		   ft_sub.c \
		   ft_andorxor.c \
		   ft_zjmp.c \
		   ft_ldi_and_lldi.c \
		   ft_sti.c \
		   ft_fork_and_lfork.c \
		   ft_aff.c \
		   ft_one_cycle.c \
		   ft_opcode.c \
		   ft_parse_vm1.c \
		   ft_parse_vm2.c \
		   ft_processus.c \
		   ft_reinit.c \
		   ft_store.c \
		   ft_tools.c \
		   ft_tools2.c \
		   ft_getparam.c \
		   ft_init_visu.c \
		   ft_visu_winner.c \
		   ft_visu_info.c \
		   ft_visual.c \
		   ft_visual2.c \
		   main_corewar.c \
		   ft_tools.c \
		   op.c \


# OBJECTS
OBJ_NAME = $(SRC_NAME:.c=.o)

# PREFIXES
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

# FLAGS
CPPFLAGS = -I./includes/ -I../libft/includes -I../../includes

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
all : libftcomp $(OBJ_PATH) $(NAME) Makefile

libftcomp:
	@$(MAKE) -C $(LIB_PATH)

$(NAME): $(OBJ)
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)....................... $(LOG_ORANGE)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $^ -o $(DST)$@ $(LIBS) $(FLAGS) $(LIB_NCURSES)
	@echo -e "--$(LOG_CLEAR)$(LOG_CYAN)$(NAME)$(LOG_NOCOLOR) compiled................. $(LOG_GREEN)✓$(LOG_NOCOLOR)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(FLAGS) $(CPPFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deleted.............. $(LOG_RED)×$(LOG_NOCOLOR)"

.PHONY: fclean
fclean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deleted.............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean $(NAME)$(LOG_NOCOLOR)"
	@rm -f $(DST)$(NAME)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deleted............... $(LOG_RED)×$(LOG_NOCOLOR)"

.PHONY: re
re:
	@$(MAKE) fclean
	@$(MAKE) all
