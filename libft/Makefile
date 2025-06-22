NAME = libft.a

HEADER = libft.h

CFLAGS = -Wall -Werror -Wextra -I.

SRC = ft_isalpha.c \
ft_bzero.c \
ft_isascii.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isprint.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_tolower.c \
ft_toupper.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \

SRC_B = ft_lstadd_back.c  ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstnew.c \
ft_lstsize.c \
ft_lstmap.c \

OBJ = $(SRC:.c=.o)

OBJB = $(SRC_B:.c=.o)

DEP = $(OBJ:.o=.d)

DEPB = $(OBJB:.o=.d)

all: $(NAME)

$(NAME): $(OBJ) libft.h
	@ar -rcs $(NAME) $(OBJ)
	@echo "Archivando"	

%.o:%.c Makefile $(HEADER)
	@cc $(CFLAGS) -c $< -o $@
	@echo "Compiling: $<"

clean:
	@rm -f $(OBJ) $(OBJB) $(DEP) $(DEPB)
	@echo "dEsTrUcTiOn"

fclean: clean
	@rm -f $(NAME)
	@echo "TOTAL DESTRUCTION"

re: fclean all

bonus: $(OBJ) $(OBJB) libft.h
	ar -rcs $(NAME) $(OBJ) $(OBJB)

.PHONY: all clean fclean re bonus

-include $(DEPS)
-include $(B_DEPS)
