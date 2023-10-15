GREEN := \033[32m
RED := \033[31m
END := \033[0m

SRCS = srcs/main.c srcs/utils/ft_atoi.c \
		srcs/utils/is_positive_number.c \
		srcs/utils/number_len_no_zero.c \
		srcs/utils/print_message.c \
		srcs/utils/round.c \
		srcs/utils/ft_itoa.c srcs/utils/get_time.c \
		srcs/init/init.c

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -pthread # -fsanitize=thread -g -Wall -Wextra -Werror

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