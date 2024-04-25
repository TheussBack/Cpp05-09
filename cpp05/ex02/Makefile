# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 15:46:17 by hrobin            #+#    #+#              #
#    Updated: 2024/03/12 17:52:10 by hrobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------colors-----------#
NC=\033[0m

Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m
Blink=\033[5m
Bold=\033[1m
#---------------------------#

NAME = Bureaucrat

CC = c++

SRC =	./srcs/main.cpp \
		./srcs/Bureaucrat.cpp \
		./srcs/AForm.cpp \
		./srcs/ShrubberyCreationForm.cpp \
		./srcs/RobotomyRequestForm.cpp \
		./srcs/PresidentialPardonForm.cpp \

OBJ = ${SRC:.cpp=.o}
DEPS = ${SRC:.cpp=.d}

INC = ./includes

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g3

.cpp.o:
	@${CC} ${CPPFLAGS} -I${INC} -c $< -o ${<:.cpp=.o}

all:	${NAME}

${NAME}:	${OBJ}

	@${CC} ${CPPFLAGS} -I${INC} ${OBJ} -o ${NAME}
	@echo "${Cyan}${Blink}- ${NAME} ready.${NC}"

clean:
	@rm -f ${OBJ}
	@echo "${Yellow}${Blink}- ${NAME} ready.${NC}"

fclean: clean
	@rm -f ${NAME} ${DEPS}
	@echo "${Red}${Blink}- ${NAME} ready.${NC}"

aclean: all clean

re: fclean all

-include : ${DEPS}

.PHONY: all clean fclean re bonus aclean
