NAME	=	ft_tail
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
SRC		=	ft_tail.c \
			print_utils.c \
			ft_atoi.c \
			main.c \
			allocation_utils.c
OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -fsanitize=address

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
