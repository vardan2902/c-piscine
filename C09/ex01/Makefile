NAME		=	libft.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SRC_DIR		=	srcs
INC_DIR		=	includes
SRC_FILES	=	ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJ_FILES	=	$(addprefix $(SRC_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
