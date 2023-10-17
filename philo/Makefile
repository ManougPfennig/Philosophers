# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 18:09:30 by mapfenni          #+#    #+#              #
#    Updated: 2023/10/17 15:55:35 by mapfenni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = src/main.c src/parsing.c src/init.c src/function.c src/init_philo.c \
src/start_philo.c src/p_routine.c src/superviser.c

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