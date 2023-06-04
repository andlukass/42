SRCS = specifiers/s_specifier.c specifiers/p_specifier.c \
	   specifiers/di_specifier.c specifiers/u_specifier.c \
	   specifiers/xx_specifier.c specifiers/c_specifier.c \
	   functions/ft_strchr.c functions/ft_putstr_len.c \
	   functions/ft_putstr_base.c functions/ft_get_length.c \
	   ft_printf.c 

OBJS = $(SRCS:.c=.o)

RM = rm -f -r
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
