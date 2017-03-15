NAME		=	fdf
FLAG		=	-Wall -Werror -Wextra
FLAGMLX		=	-lmlx -framework OpenGL -framework Appkit
SRC_DIR		=	src/
SRC_BASE	=	fdf.c map.c image.c color.c print.c ligne.c key.c
SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ_DIR		=	obj/
LIBFT		=	./libft
LFT			=	./libft/libft.a
LIBMLX		=	./minilibx_macos
LMLX		=	./minilibx_macos/libmlx.a
INCLUDES	=	-I./includes -I./libft/includes -I./minilibx_macos/
OBJ		=	$(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all: $(LFT) $(LMLX) $(NAME)

$(LFT):
	make -C $(LIBFT)

$(LMLX):
	make -C $(LIBMLX)

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) -o $(NAME) -L$(LIBFT) -lft -L$(LIBMLX) $(FLAGMLX) $(INCLUDES)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	gcc $(FLAG) -o $@ -c $< $(INCLUDES)


clean:
	make clean -C $(LIBMLX)
	make clean -C $(LIBFT)
	rm -rf obj

fclean: clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME)

re: fclean all
