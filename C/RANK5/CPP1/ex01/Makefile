CC = c++ -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp zombieHorde.cpp \
		Zombie.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = zombie

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

.cpp.o:
	$(CC) -c $< -o $@

make run:
	make ; ./$(NAME)

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all