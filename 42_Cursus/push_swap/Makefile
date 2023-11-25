CC=cc
CFLAGS=-Wall -Werror -Wextra

DIR_PRINTF=./ft_printf

SRCS=push_swap.c \
		algo.c \
		cmd1.c \
		cmd2.c \
		count.c \
		ft_lst.c \
		ft_split.c \
		number.c \
		parse.c
		split_stk.c \
OBJS=$(SRCS:.c=.o)

NAME=push_swap

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(DIR_PRINTF)
	$(CC) -o $(NAME) $(OBJS) -L$(DIR_PRINTF) -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(DIR_PRINTF) clean
	rm -rf $(OBJS)

fclean:
	make -C $(DIR_PRINTF) fclean
	rm -rf $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
