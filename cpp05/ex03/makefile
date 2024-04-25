# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 18:10:56 by hrobin            #+#    #+#              #
#    Updated: 2024/03/25 18:22:38 by hrobin           ###   ########.fr        #
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
		./srcs/Form.cpp \
		./srcs/ShrubberyCreationForm.cpp \
		./srcs/RobotomyRequestForm.cpp \
		./srcs/PresidentialPardonForm.cpp \
		./srcs/Intern.cpp \

OBJ = ${SRC:.cpp=.o}
DEPS = ${SRC:.cpp=.d}

INC = ./includes

CPPFLAGS = -Wall -Wextra -Werror -g3 -std=c++98 -MMD

.cpp.o:
	@${CC} ${CPPFLAGS} -I${INC} -c $< -o ${<:.cpp=.o}

all:	${NAME}

${NAME}:	${OBJ}

	@${CC} ${CPPFLAGS} -I${INC} ${OBJ} -o ${NAME}
	@echo "${Red}${Blink}- ${NAME} ready.${NC}"

clean:
	@rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME} ${DEPS}

aclean: all clean

re: fclean all

-include : ${DEPS}

.PHONY: all clean fclean re bonus aclean
