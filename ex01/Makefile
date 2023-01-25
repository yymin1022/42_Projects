CC=cc
CFLAGS=-Wall -Wextra -Werror

INCLUDE_DIR=./includes/
SRCS=./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c
OBJECT=$(SRCS:.c=.o)
TARGET=libft.a

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $(<) -o $(<:.c=.o)

$(TARGET): $(OBJECT)
	ar rc $(TARGET) $(OBJECT)

all: $(TARGET)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -rf $(TARGET)

re: fclean all
