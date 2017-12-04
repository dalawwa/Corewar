# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 17:48:19 by bfruchar          #+#    #+#              #
#    Updated: 2017/12/04 10:34:41 by bfruchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

FLAGS =				-Wall -Wextra -Werror

CC =				gcc

SRC =				srcs/main.c \
					srcs/end_and_free.c \
					srcs/initialize_struct.c \
					srcs/parsing_asm.c \
					srcs/parsing2_asm.c \
					srcs/add_lines_champ.c \
					srcs/ft_strsplit_three.c

OBJ =				main.o \
					end_and_free.o \
					initialize_struct.o \
					parsing_asm.o \
					parsing2_asm.o \
					add_lines_champ.o \
					ft_strsplit_three.o

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) $(OBJ) ../libft/libft.a -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
