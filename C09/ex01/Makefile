# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunhkim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 20:11:17 by hyunhkim          #+#    #+#              #
#    Updated: 2022/01/26 20:19:05 by hyunhkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libft.a

SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c\
		  srcs/ft_swap.c

OBJS	= ${SRCS:.c=.o}

INCS	= includes

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = rcs

RM = rm -f

%.o : %.c
	${CC} ${CFLAGS} -I includes -c $^ -o $@

${TARGET} : ${OBJS}
	${AR} ${ARFLAGS} ${TARGET} ${OBJS}

all: ${TARGET}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${TARGET}

re: fclean all
