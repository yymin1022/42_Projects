CC = gcc -pthread
CFLAGS = -g -Wall -Werror -Wextra

NAME = philo
SRCS = main.c \
		check_valid.c \
		cleanup.c \
		finish_routine.c \
		ft_atol.c \
		init.c utils_print.c \
		utils_mutex.c \
		run_routine.c \
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
