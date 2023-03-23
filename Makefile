CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME=libft.a
INCLUDE=libft.h
SRCS_DEFAULT=ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	 ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	 ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	 ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	 ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	 ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_BONUS=ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		   ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS_DEFAULT=$(SRCS_DEFAULT:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

ifdef BONUS
	OBJS = $(OBJS_DEFAULT) $(OBJS_BONUS)
else
	OBJS = $(OBJS_DEFAULT)
endif

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(<) -o $(@)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: 
	sleep 1
	make BONUS=1 all

all: $(NAME)

clean:
	rm -rf $(OBJS_DEFAULT) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
