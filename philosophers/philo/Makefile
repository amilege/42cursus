#<-------------------------------|VARIABLES|---------------------------------->#

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=thread -fsanitize=address

#<---------------------------------|FILES|------------------------------------>#

SRC_F = actions.c ft_check_args.c libft_utils.c main.c utils2.c utils.c
SRC_D = ./src/

OBJ_F = ${SRC_F:.c=.o}
OBJ_D = ./obj/
OBJ = ${addprefix ${OBJ_D}, ${OBJ_F}}

DEP_F = ${SRC_F:.c=.d}
DEP_D = ./dep/
DEP = ${addprefix ${DEP_D}, ${DEP_F}}

#<---------------------------------|RULES|------------------------------------>#

all: ${NAME}

${NAME}: ${OBJ_D} ${DEP_D} ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

${OBJ_D}%.o: ${SRC_D}%.c Makefile
	${CC} ${CFLAGS} -MMD -c $< -o $@
	mv ${@:.o=.d} ${DEP_D}

${OBJ_D}:
	mkdir ${OBJ_D}

${DEP_D}:
	mkdir ${DEP_D}

#<---------------------------------|PHONY|------------------------------------>#

clean:
	rm -rf ${OBJ_D} ${DEP_D}

fclean: clean
	rm -rf ${NAME}

re: fclean all

-include ${DEP}

.PHONY: all clean fclean re
#<---------------------------------------------------------------------------->#

