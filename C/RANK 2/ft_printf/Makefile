SRCS  = 		specifiers/s_specifier.c specifiers/p_specifier.c \
				specifiers/c_specifier.c specifiers/di_specifier.c \
				ft_printf.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME) clean

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) ./specifiers/*.o 
				$(RM) *.o

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)