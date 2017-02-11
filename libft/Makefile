# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 17:40:06 by thou              #+#    #+#              #
#    Updated: 2017/02/09 17:31:16 by thou             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -c -Wall -Wextra -Werror -Iincludes
FILE = *.c
FILE1 =  *.o
all: $(NAME)

$(NAME):
	gcc $(FLAG) $(FILE)
	ar rc $(NAME) $(FILE1)
	ranlib $(NAME)

f: fclean

clean:
	/bin/rm -rf $(FILE1)

fclean:	clean
	/bin/rm -rf $(NAME)

re:		fclean all
