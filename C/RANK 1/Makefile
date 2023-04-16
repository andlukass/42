SRCS			= ft_strlen.c ft_memcmp.c
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME) clean

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) *.o

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)