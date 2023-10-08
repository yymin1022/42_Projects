CC=gcc
CFLAGS=-Wall -Wextra -Werror

CLIENT=client
CLIENT_SRC=client.c
CLIENT_OBJ=$(CLIENT_SRC:.c=.o)

SERVER=sever
SERVER_SRC=server.c
SERVER_OBJ=$(SERVER_SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $(<) -o $(@)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(<) -o $(@)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(<) -o $(@)

all: $(SERVER) $(CLIENT)

clean:
	rm -rf $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	rm -rf $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
