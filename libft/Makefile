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

NAME = libft.a
	
SRCS = ft_split.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c \
ft_putchar_fd.c ft_substr.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
ft_tolower.c ft_toupper.c ft_strjoin.c ft_strmapi.c ft_itoa.c ft_strtrim.c \

BNSSRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstclear.c\
ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstmap.c\
ft_lstiter.c


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
