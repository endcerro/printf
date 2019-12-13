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

BNSSRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstclear.c\
ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstmap.c\
ft_lstiter.c


#BNSOBJ = ${BNSSRC:.c=.o}

OBJS = ${SRCS:.c=.o}

CC = gcc

HEADER = libft.h

LIBS = libft.a

run : ${OBJS}
	cd libft && make
	${CC} ${CFLAGS} $(LIBS) -I ./ *.c -L libft/

run2 :
	cd libft && make && mv libft.a ../.
	${CC} ${CFLAGS} -I ./ *.c -L libft.a

all : $(NAME)

.c.o:
	${CC} ${CFLAGS} -I ./ -c $< -o ${<:.c=.o}

#bonus: ${BNSOBJ} ${OBJS} ${HEADER}
#	ar rcs $(NAME) ${OBJS} ${BNSOBJ} ${HEADER}	

#$(NAME): ${OBJS} ${HEADER}
#	ar rcs $(NAME) ${OBJS} ${HEADER}

#fclean : clean
#	rm -rf  ./$(NAME)

#clean :
#	rm -rf ${OBJS} ${BNSOBJ}
	
#re : fclean all

#.PHONY: clean all fclean re bonus
