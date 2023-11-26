CC=cc
CFLAGS=-Wall -Werror -Wextra

DIR_PRINTF=./ft_printf

BONUS_SRCS=bonus/checker.c \
		bonus/cmd1.c \
		bonus/cmd2.c \
		bonus/ft_lst.c \
		bonus/ft_split.c \
		bonus/number.c \
		bonus/parse.c \
		bonus/get_next_line/get_next_line_bonus.c \
		bonus/get_next_line/get_next_line_utils.c

BONUS_OBJS=$(BONUS_SRCS:.c=.o)

BONUS_NAME=checker

SRCS=push_swap.c \
		algo.c \
		cmd1.c \
		cmd2.c \
		count.c \
		ft_lst.c \
		ft_split.c \
		number.c \
		parse.c \
		split_stk.c

OBJS=$(SRCS:.c=.o)

NAME=push_swap

all: $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	make -C $(DIR_PRINTF)
	$(CC) -o $(BONUS_NAME) $(BONUS_OBJS) -L$(DIR_PRINTF) -lftprintf

$(NAME): $(OBJS)
	make -C $(DIR_PRINTF)
	$(CC) -o $(NAME) $(OBJS) -L$(DIR_PRINTF) -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(DIR_PRINTF) clean
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean:
	make -C $(DIR_PRINTF) fclean
	rm -rf $(OBJS) $(BONUS_OBJS) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
