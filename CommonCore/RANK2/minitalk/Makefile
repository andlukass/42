CFLAGS = -Wall -Wextra -Werror

SRCS = src/client.c src/server.c utils/ft_atoi_base.c \
	utils/ft_itoa.c utils/ft_strlen.c

OBJS = $(SRCS:.c=.o)

NAME = server client

all: $(NAME)

server: src/server.o utils/ft_atoi_base.o utils/ft_itoa.o utils/ft_strlen.o
	$(CC) $(CFLAGS) -o $@ $^

client: src/client.o utils/ft_atoi_base.o utils/ft_itoa.o utils/ft_strlen.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
