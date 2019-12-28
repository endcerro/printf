# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 16:51:20 by edal--ce          #+#    #+#              #
#    Updated: 2019/12/28 08:27:34 by edal--ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS = -Wall -Wextra -Werror 

NAME = libft.a
	
SRCS = 	src/ft_split.c 				\
		src/ft_putnbr_fd.c 			\
		src/ft_putendl_fd.c 		\
		src/ft_putstr_fd.c 			\
		src/ft_putchar_fd.c 		\
		src/ft_substr.c 			\
		src/ft_atoi.c 				\
		src/ft_bzero.c 				\
		src/ft_calloc.c 			\
		src/ft_isalnum.c 			\
		src/ft_isalpha.c			\
		src/ft_isascii.c 			\
		src/ft_isdigit.c 			\
		src/ft_isprint.c 			\
		src/ft_memccpy.c 			\
		src/ft_memchr.c 			\
		src/ft_memcmp.c 			\
		src/ft_memcpy.c 			\
		src/ft_memmove.c 			\
		src/ft_memset.c 			\
		src/ft_strchr.c 			\
		src/ft_strdup.c 			\
		src/ft_strlcat.c 			\
		src/ft_strlcpy.c 			\
		src/ft_strlen.c 			\
		src/ft_strncmp.c 			\
		src/ft_strnstr.c 			\
		src/ft_strrchr.c 			\
		src/ft_tolower.c 			\
		src/ft_toupper.c 			\
		src/ft_strjoin.c 			\
		src/ft_strmapi.c 			\
		src/ft_itoa.c 				\
		src/ft_strtrim.c 			\
		src/ft_convert_base.c 		\
		src/ft_convert_base2.c 		\
		src/ft_abs.c

BNSSRC = 	src/ft_lstnew.c \
			src/ft_lstadd_front.c \
			src/ft_lstsize.c \
			src/ft_lstclear.c\
			src/ft_lstlast.c \
			src/ft_lstadd_back.c \
			src/ft_lstdelone.c \
			src/ft_lstmap.c\
			src/ft_lstiter.c


BNSOBJ = ${BNSSRC:.c=.o}

OBJS = ${SRCS:.c=.o}

CC = gcc

HEADER = libft.h

all : $(NAME)

.c.o:
	${CC} ${CFLAGS} -I ./ -c $< -o ${<:.c=.o}

bonus: ${BNSOBJ} ${OBJS} ${HEADER}
	ar rcs $(NAME) ${OBJS} ${BNSOBJ} ${HEADER}	

$(NAME): ${OBJS} ${HEADER}
	ar rcs $(NAME) ${OBJS} ${HEADER}

fclean : clean
	rm -rf  ./$(NAME)

clean :
	rm -rf ${OBJS} ${BNSOBJ}
	
re : fclean all

.PHONY: clean all fclean re bonus
