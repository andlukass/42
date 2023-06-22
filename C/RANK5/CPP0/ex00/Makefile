CC = g++ -Wall -Werror -Wextra

SRCS = megaphone.cpp

OBJS = $(SRCS:.c=.o)

NAME = megaphone

all = $(NAME)

megaphone: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

