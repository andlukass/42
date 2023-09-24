NAME		= phonebook
CC		= g++
FLAGS    	= -Wall -Wextra -Werror -std=c++98

RED		= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
CYAN 		= \033[1;36m

SRCS		=	main.cpp \
		Contact.cpp PhoneBook.cpp search.cpp

OBJS		= ${SRCS:.cpp=.o}

.o:
		${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS}
			@echo "${GREEN}Compiling ${CYAN}${NAME} ..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "${GREEN}${NAME} created ✔️"

all:		${NAME}

clean:
			@ rm -f ${OBJS}
			@ echo "${RED}Deleting ${CYAN}${NAME} objs ✔️"

fclean:		clean
			@ rm -f ${NAME}
			@ echo "${RED}Deleting ${CYAN}${NAME} binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re
