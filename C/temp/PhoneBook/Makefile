CC = g++

SRCS = main.cpp \
		PhoneBook.cpp Contact.cpp

OBJS= $(SRCS:.cpp=.o)

NAME= phonebook

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

.cpp.o:
	$(CC) -c $< -o $@

make run: 
	make ; ./phonebook

clean: 
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all