CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME=libftprintf.a
SRCS=ft_printf.c ft_print_format_num.c ft_print_format_str.c
OBJS=$(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $(<) -o $(@)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
