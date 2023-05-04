SRCS = get_next_line.c get_next_line.h

OBJS = (SRCS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

.objs/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r .objs

fclean: clean
	$(RM) $(NAME)

re: fclean all
