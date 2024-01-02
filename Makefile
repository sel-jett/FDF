SRC = get_next_line.c get_next_line_utils.c strtok_two.c \
	  ft_convert.c fdf_utils.c my_malloc.c strtok.c main.c \
	  fdf_utils_2.c

OBJ = ${SRC:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = fdf

all: ${NAME}

%o : %c fdf.h
	${CC} ${FLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

clean:
	rm -f ${OBJ}

fclean:
	rm -f ${OBJ} ${NAME}

re: clean all

.PHONY: clean fclean re all
