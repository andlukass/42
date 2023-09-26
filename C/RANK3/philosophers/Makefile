GREEN := \033[32m
RED := \033[31m
END := \033[0m

RM = rm -f
CFLAGS = -pthread -fsanitize=threads # -Wall -Wextra -Werror

SRCS = src/main.c src/utils/ft_atoi.c src/time/ms_counter.c \
		src/actions/actions.c

OBJS = $(SRCS:%.c=%.o)

NAME = philosophers

all:	$(NAME)

$(NAME):$(OBJS)
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