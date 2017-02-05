NAME=fdf
FLAG=-Wall -Werror -Wextra
FLAGMLX=-lmlx -framework OpenGL -framework Appkit
SRC=*.c
LIB=./libft
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C $(LIB)
	gcc -c $(FALG) $(FLAGMLX) $(SRC)
	gcc $(OBJ) -o $(NAME) -L$(LIB) -lft

clean:
	make clean -C $(LIB)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIB)
	rm -rf $(NAME)

re: fclean all
