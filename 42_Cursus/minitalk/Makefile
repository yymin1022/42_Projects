CC=cc
CFLAGS=-Wall -Wextra -Werror

CLIENT=client
CLIENT_SRC_MANDATORY=client.c client_utils.c
CLIENT_OBJ_MANDATORY=$(CLIENT_SRC_MANDATORY:.c=.o)
CLIENT_SRC_BONUS=client_bonus.c client_utils.c
CLIENT_OBJ_BONUS=$(CLIENT_SRC_BONUS:.c=.o)

SERVER=server
SERVER_SRC_MANDATORY=server.c
SERVER_OBJ_MANDATORY=$(SERVER_SRC_MANDATORY:.c=.o)
SERVER_SRC_BONUS=server_bonus.c
SERVER_OBJ_BONUS=$(SERVER_SRC_BONUS:.c=.o)

ifdef MAKE_BONUS
	CLIENT_SRC = $(CLIENT_SRC_BONUS)
	CLIENT_OBJ = $(CLIENT_OBJ_BONUS)
	SERVER_SRC = $(SERVER_SRC_BONUS)
	SERVER_OBJ = $(SERVER_OBJ_BONUS)
else
	CLIENT_SRC = $(CLIENT_SRC_MANDATORY)
	CLIENT_OBJ = $(CLIENT_OBJ_MANDATORY)
	SERVER_SRC = $(SERVER_SRC_MANDATORY)
	SERVER_OBJ = $(SERVER_OBJ_MANDATORY)
endif

all: $(CLIENT) $(SERVER)

bonus:
	make MAKE_BONUS=1 all

%.o: %.c
	$(CC) $(CFLAGS) -c $(<) -o $(@)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(^) -o $(@)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(^) -o $(@)

clean:
	rm -rf $(CLIENT_OBJ_MANDATORY) $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_MANDATORY) $(SERVER_OBJ_BONUS)

fclean: clean
	rm -rf $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
