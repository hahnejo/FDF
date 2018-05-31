
NAME = fdf_bin
SRC = $(wildcard src/*.c)
OPTIONS = minilibx/
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -I include -L src/libft -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit
OBJ = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	cd src/libft && make -f Makefile
	mv src/libft/libft.a src
	gcc -o $(NAME) $(CFLAGS) $(SRC) src/libft.a

clean:
	cd src/libft && make fclean

fclean:
	cd src/libft && make fclean
	rm -rf $(NAME)
	rm -rf src/libft.a

re: fclean $(NAME)

.PHONY: clean fclean re
