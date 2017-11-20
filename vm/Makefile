# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 03:03:10 by mapandel          #+#    #+#              #
#    Updated: 2017/09/26 12:24:57 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	corewar
LIB =	libft.a
#				Compilation

CC = 	gcc
CFLAGS = -Wall -Wextra -Werror

#			Sources

PATH_LIB = ../libft/
PATH_SRCS = ./srcs/
PATH_HEAD = ./includes/
PATH_OBJS = ./objs/

SRCS_NAME = main.c \
			get_nb_cors.c \
			check_opts.c \
			create_players.c \
			ft_stradd_c_end.c \
			print_debug.c \
			go_match.c \
			create_arena.c

CW_SRCS = $(addprefix $(PATH_SRCS), $(SRCS_NAME))
CW_OBJS = $(addprefix $(PATH_OBJS), $(SRCS_NAME:.c=.o))

#			Colors

DEF =			\033[0m
GRA =			\033[1m
SOU =			\033[4m
BLI =			\033[5m
INV =			\033[7m
BLA =			\033[30m
RED =			\033[31m
GRE =			\033[32m
YEL =			\033[33m
BLU =			\033[34m
PUR =			\033[35m
CYA =			\033[36m
WHI =			\033[37m
BACK_BLA =		\033[40m
BACK_RED =		\033[41m
BACK_GRE =		\033[42m
BACK_YEL =		\033[43m
BACK_BLU =		\033[44m
BACK_PUR =		\033[45m
BACK_CYA =		\033[46m
BACK_WHI =		\033[47m

#			Main Rules

.PHONY: all conv ft_printf get_next is lst mem put sort str tab to wstr \
	indexion re glu  clean fclean

all: create_libft create_path_obj $(NAME)

create_path_obj:
	mkdir -p $(PATH_OBJS) 2> /tmp/a.del

create_libft:
	make -C $(PATH_LIB)

$(NAME):
#	echo $(SRCS_NAME)
#	echo $(CW_OBJS)
#	echo $(CW_SRCS)
	make $(CW_OBJS)
	$(CC) $(CFLAGS) -o $@ $(CW_OBJS) $(PATH_LIB)$(LIB)


re: fclean all

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	$(CC) $(CFLAGS) -I$(PATH_HEAD) -o $@ -c $^

clean:
	make clean -C $(PATH_LIB)
	@echo "$(PUR)--::$(NAME) Binary Deleting::--$(DEF)"
	@rm -rf $(PATH_OBJS)

fclean: clean
	make fclean -C $(PATH_LIB)
	@echo "$(RED)--::$(NAME) Deleting::--$(DEF)"
	@rm -rf $(NAME)
