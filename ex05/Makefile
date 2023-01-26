CC=cc
CFLAGS=-Wall -Wextra -Werror

INCLUDE=doop.h
SRCS=main.c number.c str.c
OBJECT=$(SRCS:.c=.o)
TARGET=do-op

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(<) -o $(<:.c=.o)

$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) -o $(TARGET)

all: $(TARGET)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -rf $(TARGET)

re: fclean all
