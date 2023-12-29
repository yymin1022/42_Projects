CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = philo
SRCS = main.c \
		init.c \
		routine.c \
		utils.c \
		utils_print.c \
		utils_routine.c
OBJS = $(SRCS:.c=.o)

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
