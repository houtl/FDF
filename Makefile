NAME		=	fdf
FLAG		=	-Wall -Werror -Wextra
FLAGMLX		=	-lmlx -framework OpenGL -framework Appkit
SRC			=	*.c
LIBFT		=	./libft
LIBMLX		=	./minilibx_macos
INCLUDES	=	-I./libft/includes -I./minilibx_macos/
OBJ			=	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	make -C $(LIBMLX)
	gcc -c $(FALG) $(FLAGMLX) $(SRC) $(INCLUDES)
	gcc $(OBJ) -o $(NAME) -L$(LIBFT) -lft -L$(LIBMLX) $(INCLUDES)

clean:
	make clean -C $(LIBMLX)
	make clean -C $(LIBFT)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME)

re: fclean all
