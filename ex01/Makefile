CC=cc
CFLAGS=-Wall -Wextra -Werror

INCLUDE_DIR=./includes
SRC_DIR=./srcs
INCLUDE=$(INCLUDE_DIR)/ft.h
OBJECT=$(SRC_DIR)/ft_putchar.o $(SRC_DIR)/ft_putstr.o $(SRC_DIR)/ft_strcmp.o $(SRC_DIR)/ft_strlen.o $(SRC_DIR)/ft_swap.o
TARGET=libft.a

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(TARGET): $(OBJECT)
	ar rc $(TARGET) $(OBJECT)

all: $(TARGET)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -rf $(TARGET)

re: fclean all
