SRCS = main.c ft_check_args.c ft_initstack.c \
libft_utils.c ordenar.c swap.c push.c \
rotate.c reverse.c chunks_ord.c cost.c \
movements.c free.c


OBJS = ${SRCS:.c=.o}

NAME = push_swap
INCLUDE = push_swap.h ./libft/
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g


%.o:%.c $(INCLUDE) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

all: libft ${NAME} Makefile


libft:
	$(MAKE) -C ./libft/

${NAME}: ${OBJS} ./libft/libft.a ${INCLUDE}
			${CC} $(CFLAGS) -o ${NAME} ${OBJS} -L./libft -lft

clean: 		
			${RM} ${OBJS}
			$(MAKE) -C ./libft clean

fclean: 	clean
			${RM} ${NAME}
			$(MAKE) -C ./libft fclean

re:			fclean all

.PHONY: all clean fclean re libft
