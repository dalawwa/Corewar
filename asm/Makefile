NAME = asm

FLAGS =				-Wall -Wextra -Werror

CC =				gcc

SRC =				main.c

OBJ =				main.o

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) $(OBJ) ../libft/libft.a -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
