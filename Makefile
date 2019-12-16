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

NAME = libftprintf.a
	
SRCS = ft_printf.c ft_printf_utils.c \
processflags.c ultoa.c 

LFTDIR = ./libft/

LFTSRCS = libft/ft_split.c libft/ft_putnbr_fd.c libft/ft_putendl_fd.c libft/ft_putstr_fd.c \
libft/ft_putchar_fd.c libft/ft_substr.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_memccpy.c libft/ft_memchr.c \
libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_strchr.c libft/ft_strdup.c \
libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c \
libft/ft_tolower.c libft/ft_toupper.c libft/ft_strjoin.c libft/ft_strmapi.c libft/ft_itoa.c libft/ft_strtrim.c \
libft/ft_convert_base.c libft/ft_convert_base2.c \
libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstclear.c\
libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstdelone.c libft/ft_lstmap.c\
libft/ft_lstiter.c

#BNSOBJ = ${BNSSRC:.c=.o}

OBJS = ${SRCS:.c=.o}

LFTOBJS = ${LFTSRCS:.c=.o}

CC = gcc

HEADER = ft_printf.h libft.h

LIBS = libft.a

#run : ${OBJS}
#	cd libft && make
#	${CC} $(LIBS) -I ./ *.c -L libft/

all : $(NAME)

.c.o:
	${CC} ${CFLAGS} -I ./ -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${LFTOBJS}
	ar rcs $(NAME) ${OBJS} ${LFTOBJS} ${HEADER}

#bonus: ${BNSOBJ} ${OBJS} ${HEADER}
#	ar rcs $(NAME) ${OBJS} ${BNSOBJ} ${HEADER}	

#$(NAME): ${OBJS} ${HEADER}
#	ar rcs $(NAME) ${OBJS} ${HEADER}

fclean : clean
	rm -rf  ./$(NAME)

clean :
	rm -rf ${OBJS}
	
#re : fclean all

#.PHONY: clean all fclean re bonus
