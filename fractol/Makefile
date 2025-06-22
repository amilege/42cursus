SRC = main.c color.c fractals.c init.c keys.c render.c\
init_hook.c utils.c utils2.c

NAME = fractol

CFLAGS = -Werror -Wall -Wextra

INCLUDE = fractal.h 

CC =	gcc

RM = rm -f

BIBLI = ./libft/libft.a  

OBJS = ${SRC:.c=.o}

%.o:%.c ${INCLUDE} $(BIBLI) Makefile
	${CC} ${CFLAGS} -c $< -o $@

all: mlx libft ${NAME} 

mlx:
	$(MAKE) -C ./mlx

libft:
	$(MAKE) -C ./libft/

${NAME}: $(OBJS) ./mlx/libmlx.a $(BIBLI) $(INCLUDE)
	$(CC) $(CFLAGS) $(BIBLI) $(OBJS) -L  ./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		${RM} ${OBJS}
		$(MAKE) -C ./mlx clean
		$(MAKE)  -C ./libft clean

fclean:	clean
		${RM} ${NAME}
		$(MAKE) -C ./libft fclean


re:	fclean all

.PHONY: all clean fclean re mlx libft
