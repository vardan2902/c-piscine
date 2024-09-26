NAME		=	rush-02
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
INC_DIR		=	./
SRC_FILES	=	dict_utils.c \
				error_utils.c \
				parse_utils2.c \
				string_utils2.c \
			   	conversion_utils.c \
				dict_utils2.c \
				main.c \
				dict_utils3.c \
				parse_utils.c \
				string_utils.c
OBJ_FILES	=	$(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(OBJ_FILES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
