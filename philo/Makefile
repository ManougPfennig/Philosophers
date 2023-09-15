# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 18:09:30 by mapfenni          #+#    #+#              #
#    Updated: 2023/09/15 11:08:30 by mapfenni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = src/main.c src/parsing.c src/init_struct.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	gcc ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS} ${BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all