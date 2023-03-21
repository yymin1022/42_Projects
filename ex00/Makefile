NAME = rush-02
SRCS = $(addprefix srcs/, main.c ft_putstr.c ft_strlen.c ft_str_is_numeric.c translate.c dict.c list.c parse.c convert.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
