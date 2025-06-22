NAME_C = client

INCLUDES = ./include/libft/libft.a ./include/printf/libftprintf.a

NAME_S = server

SRCS = server.c 

SRCC = client.c

HEADER = minitalk.h

CC = gcc

OBJC = $(SRCC:.c=.o)
OBJS = $(SRCS:.c=.o)

DEPC = $(SRCC:.c=.d)
DEPS = $(SRCS:.c=.d)


CFLAGS = -Wall -Werror -Wextra 

RM = rm -f


all: libft printf $(NAME_C) $(NAME_S)

%.o:%.c $(HEADER)
	$(CC) -MMD $(CFLAGS) -c $< -o $@

libft: 
	$(MAKE) -C ./include/libft/

printf: 
	$(MAKE) -C ./include/printf/

$(NAME_C): $(OBJC) $(INCLUDES) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJC) -o $(NAME_C)

$(NAME_S): $(OBJS) $(INCLUDES) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME_S)

clean:
		$(RM) ${OBJS} $(OBJC) $(DEPC) $(DEPS)
		$(MAKE) -C ./include/libft clean
		$(MAKE) -C ./include/printf clean

fclean:	clean
		$(RM) $(NAME_C) $(NAME_S)
		$(MAKE) -C ./include/libft fclean
		$(MAKE) -C ./include/printf fclean


re:	fclean all

.PHONY: all clean fclean re	
-include $(DEPC) $(DEPS)

	

