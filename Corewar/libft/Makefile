# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvannest <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 13:22:43 by gvannest          #+#    #+#              #
#    Updated: 2018/06/15 15:09:19 by gvannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a

VPATH = . src_printf

SRC_NAME = ft_putnbr.c ft_putchar.c ft_strlen.c ft_putstr.c ft_strdup.c ft_strcpy.c \
		   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		   ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
		   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		   ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		   ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
		   ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
		   ft_strtrim.c ft_strsplit.c ft_itoa.c ft_memccpy.c ft_putendl.c ft_putchar_fd.c \
		   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
		   ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_power.c \
		   ft_sqrt.c ft_isprime.c ft_lstpushback.c ft_lstlen.c ft_nextsqrt.c ft_lstrev.c \
		   ft_strndup.c get_next_line.c ft_strrev.c ft_itoabase_u.c ft_itoabase_s.c\
		   ft_printf.c ft_buffer.c ft_control_flags.c \
		   ft_clean_flags.c ft_cast_arg.c ft_typed.c ft_typeu.c \
		   ft_types.c ft_typec.c ft_reinit_struct.c ft_typeo.c ft_typex.c \
		   ft_typep.c ft_typepercent.c ft_type_unicodec.c ft_wcharconv.c \
		   ft_type_unicodes.c ft_typeb.c ft_couleur.c ft_sqrt_heron.c \
		   ft_max.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I./include

SRC = $(addprefix $(VPATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@

$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)
	@gcc $(FLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $@

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
