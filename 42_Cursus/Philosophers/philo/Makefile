CC = gcc -pthread
CFLAGS = -g -Wall -Werror -Wextra -fsanitize=thread -g

NAME = philo
SRCS = main.c \
		check_valid.c \
		cleanup.c \
		ft_atol.c \
		init.c \
		routine_finish.c \
		routine_run.c \
		utils_mutex.c \
		utils_print.c \
		utils_time.c
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
