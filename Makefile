# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 13:36:18 by jtaravel          #+#    #+#              #
#    Updated: 2023/01/31 15:29:14 by jtaravel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES =	testmain.cpp \

S_PATH  =       srcs/
O_PATH  =       ./
O_PATHM =       ./
I_PATH  =       includes/

SRCS    =       ${addprefix ${S_PATH}, ${FILES}}
OBJS    =       ${FILES:.cpp=.o}
OBJSM   =       ${FILES:.cpp=.o}

HEADERS =	includes

NAME =	ft_containers
NAMEM =	std_containers

CC =	c++

RM =	rm -f

CFLAGS =	-Wall -Wextra -Werror -std=c++98 -g3
CFLAGSM =	-Wall -Wextra -Werror -std=c++98 -g3 -D STD=1

${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME} -I ${I_PATH}
		${CC} ${OBJSM} ${CFLAGSM} -o ${NAMEM} -I ${I_PATH}

std:		${OBJS}
		${CC} ${OBJSM} ${CFLAGSM} -o ${NAME} -I ${I_PATH}
	
${O_PATH}%.o:   ${S_PATH}%.cpp
		${CC} ${CFLAGS} -c $< -o $@ -I ${I_PATH}


all:		${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME} ${NAMEM}

re:		fclean all

.PHONY:		all clean flcean re
