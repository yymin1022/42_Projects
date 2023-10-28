CC=cc
CFLAGS=-Wall -Werror -Wextra

DIR_LIBFT=./libft
DIR_MLX=./mlx
DIR_PRINTF=./ft_printf

LIB_MLX=-L$(DIR_MLX) -lmlx -Imlx -framework OpenGL -framework AppKit

SRCS=so_long.c \
		so_long_utils.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c
OBJS=$(SRCS:.c=.o)

NAME=so_long

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(DIR_LIBFT)
	make -C $(DIR_MLX)
	make -C $(DIR_PRINTF)
	$(CC) -o $(NAME) $(OBJS) -L$(DIR_LIBFT) -lft -L$(DIR_PRINTF) -lftprintf $(LIB_MLX)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@

clean:
	make -C $(DIR_LIBFT) clean
	make -C $(DIR_MLX) clean
	make -C $(DIR_PRINTF) clean
	rm -rf $(OBJS)

fclean:
	make -C $(DIR_LIBFT) fclean
	make -C $(DIR_MLX) clean
	make -C $(DIR_PRINTF) fclean
	rm -rf $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
