CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME=libft.a
INCLUDE=libft.h
SRCS=ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c
OBJECTS=$(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(<) -o $(<:.c=.o)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
