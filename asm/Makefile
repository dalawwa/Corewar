# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 17:48:19 by bfruchar          #+#    #+#              #
#    Updated: 2017/11/28 16:33:31 by bfruchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

FLAGS =				-Wall -Wextra -Werror

CC =				gcc

SRC =				main.c \
					end_and_free.c \
					initialize_struct.c \
					parsing_asm.c \
					parsing2_asm.c \
					add_lines_champ.c

OBJ =				main.o \
					end_and_free.o \
					initialize_struct.o \
					parsing_asm.o \
					parsing2_asm.o \
					add_lines_champ.o

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) $(OBJ) ../libft/libft.a -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
