# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 17:48:19 by bfruchar          #+#    #+#              #
#    Updated: 2018/01/30 15:16:23 by bfruchar         ###   ########.fr        #
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
					srcs/get_op_code.c \
					srcs/check_args.c \
					srcs/check_is_reg.c \
					srcs/check_is_dir.c \
					srcs/check_is_ind.c \
					srcs/check_labels.c \
					srcs/creation_cor.c \
					srcs/creation_cor2.c \
					srcs/creation_cor3.c \
					srcs/option_a_2.c \
					srcs/option_a_3.c \
					srcs/option_a_4.c \
					srcs/option_a.c

OBJ =				main.o \
					end_and_free.o \
					initialize_struct.o \
					parsing_asm.o \
					parsing2_asm.o \
					add_lines_champ.o \
					get_op_code.o \
					check_args.o \
					check_is_reg.o \
					check_is_dir.o \
					check_is_ind.o \
					check_labels.o \
					creation_cor.o \
					creation_cor2.o \
					creation_cor3.o \
					option_a_2.o \
					option_a_3.o \
					option_a_4.o \
					option_a.o

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) $(OBJ) ../libft/libft.a -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
