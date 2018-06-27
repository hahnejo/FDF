# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjo <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/26 16:40:50 by hjo               #+#    #+#              #
#    Updated: 2018/06/26 16:40:51 by hjo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = $(wildcard src/*.c)
OPTIONS = minilibx/
CFLAGS = -Wall -Wextra -Werror -I include -L src/libft -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit
OBJ = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	cd src/libft && make -f Makefile
	mv src/libft/libft.a src
	cd minilibx && make
	gcc -o $(NAME) $(CFLAGS) $(SRC) src/libft.a

clean:
	cd src/libft && make fclean

fclean:
	cd src/libft && make fclean
	cd minilibx && make clean
	rm -rf $(NAME)
	rm -rf src/libft.a

re: fclean $(NAME)

.PHONY: clean fclean re
