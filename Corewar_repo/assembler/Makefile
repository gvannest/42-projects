# COMPILATION
CC = gcc
CFLAGS = -Wall -Wextra -Werror

DEFRULE = all
#BINARY
NAME = asm
DST = ./

# PATHS
LIBS = ../libft/libft.a
LIB_PATH = ../libft/
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/ $(LIB_PATH)/includes/

# SOURCES
SRC_NAME = main.c \
		   ft_check_argv.c \
		   ft_token_type.c \
		   ft_token_type2.c \
		   ft_token_add.c \
		   op.c \
		   ft_parsing.c \
		   ft_parse_correctly.c \
		   analyse_separator.c \
		   ft_retrieve_line.c \
		   ft_errorm.c \
		   ft_fill_labels.c \
		   ft_is_smthg.c \
		   ft_load_champ.c \
		   ft_display_cor.c \
		   ft_token_free.c \
		   ft_type_char.c \
		   ft_get_value.c \
		   ft_create_champ.c \
		   ft_write_cor.c \
		   ft_find_index.c \
		   ft_check_token.c \
		   ft_token_load.c \
		   ft_swap_bytes.c \
		   ft_options.c \
		   ft_open_champ.c \
		   ft_load_champ_param.c \
		   ft_init_info.c \
		   ft_help.c \
		   ft_free.c \
		   ft_error.c \
		   ft_error2.c	\
		   ft_toomuch_parsing.c



# OBJECTS
OBJ_NAME = $(SRC_NAME:.c=.o)
DEPS = $(shell find . -regex ".*\.[ch]")

# PREFIXES
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

DEBUG = no
ifeq ($(DEBUG), yes)
	FLAGS = -g -w
endif

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
#

default:
	@$(MAKE) $(DEFRULE)

.PHONY: all
all : libftcomp $(OBJ_PATH) $(NAME)

libftcomp:
	@$(MAKE) -C $(LIB_PATH)

$(NAME): Makefile $(DEPS) $(OBJ)
	
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)....................... $(LOG_ORANGE)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(OBJ) $(INC) $(LIBS) -o $(DST)$@
	@echo -e "--$(LOG_CLEAR)$(LOG_CYAN)$(NAME)$(LOG_NOCOLOR) compiled................. $(LOG_GREEN)✓$(LOG_NOCOLOR)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(INC) -c $^ -o $@

.PHONY: clean
clean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@$(RM) -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deleted.............. $(LOG_RED)×$(LOG_NOCOLOR)"

.PHONY: fclean
fclean: clean
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean $(NAME)$(LOG_NOCOLOR)"
	@$(RM) -f $(NAME)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deleted............... $(LOG_RED)×$(LOG_NOCOLOR)"

.PHONY:re
re:
	@$(MAKE) fclean
	@$(MAKE) all

norme:
	norminette $(SRC)
	norminette ./includes/*.h
