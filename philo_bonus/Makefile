# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 18:42:21 by shovsepy          #+#    #+#              #
#    Updated: 2021/08/19 18:42:24 by shovsepy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS = $(shell find "." -name "*.c")
OBJS = ${SRCS:.c=.o}

CC = gcc
FLAGS = -Wall -Wextra -Werror
PTHREADS = -lpthread

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
		@${CC} ${FLAGS} ${OBJS} ${PTHREADS}  -o ${NAME}

clean:
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

