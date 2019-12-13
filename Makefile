# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 16:51:20 by edal--ce          #+#    #+#              #
#    Updated: 2019/11/19 16:51:25 by edal--ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS = -Wall -Wextra -Werror 

NAME = printf.a
	
SRCS = main.c ft_printf.c ft_printf_utils.c

#BNSOBJ = ${BNSSRC:.c=.o}

OBJS = ${SRCS:.c=.o}

CC = gcc

HEADER = libft.h

LIBS = libft.a

run : ${OBJS}
	cd libft && make
	${CC} ${CFLAGS} $(LIBS) -I ./ *.c -L libft/

all : $(NAME)

.c.o:
	${CC} ${CFLAGS} -I ./ -c $< -o ${<:.c=.o}

#bonus: ${BNSOBJ} ${OBJS} ${HEADER}
#	ar rcs $(NAME) ${OBJS} ${BNSOBJ} ${HEADER}	

#$(NAME): ${OBJS} ${HEADER}
#	ar rcs $(NAME) ${OBJS} ${HEADER}

#fclean : clean
#	rm -rf  ./$(NAME)

clean :
	rm -rf ${OBJS}
	
#re : fclean all

#.PHONY: clean all fclean re bonus
