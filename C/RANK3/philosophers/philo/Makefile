GREEN := \033[32m
RED := \033[31m
END := \033[0m

SRCS = src/main.c src/init/init.c src/utils/is_positive_number.c \
		src/utils/ft_atoi.c src/utils/number_len_no_zero.c \
		src/actions/actions.c src/actions/checkers.c \
		src/time/time.c

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -pthread -Wall -Wextra -Werror # -fsanitize=thread -g

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(GREEN)> Compilation done!\n$(END)"

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJS)
		@echo "\n$(RED)> Cleaned!\n$(END)"

fclean:	clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re