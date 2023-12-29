CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = philo
SRCS = main.c \
		action.c \
		action_util.c \
		util_2.c \
		util.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
