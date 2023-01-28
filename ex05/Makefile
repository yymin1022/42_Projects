CC=cc
CFLAGS=-Wall -Wextra -Werror

INCLUDE=doop.h
SRCS=main.c number.c operator.c str.c
OBJECT=$(SRCS:.c=.o)
TARGET=do-op

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(<) -o $(<:.c=.o)

$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) -o $(TARGET)

all: $(TARGET)

clean:
	rm -f $(OBJECT)
