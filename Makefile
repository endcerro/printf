# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 17:54:38 by edal--ce          #+#    #+#              #
#    Updated: 2019/12/28 10:10:15 by edal--ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	src/ft_printf.c \
		src/ft_ultoa.c \
		src/process_types.c \
		src/utils.c \
		src/process_other.c \
		src/more_utils.c
			
OBJS = $(SRCS:.c=.o)

INCL = header/

HEADER = $(INCL)ft_printf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBLINK = -L./ -lftprintf

LIB = libft/

OBJLIB = $(LIB)/src/*.o

LIBFT = $(LIB)libft.a

all : test $(NAME)

$(OBJS) : %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INCL) -c $< -o $@ 

$(NAME) : $(OBJS)
	ar rcs $@ $(OBJS) $(OBJLIB)

test :
	$(MAKE) -C libft all

cleanlibft :
	$(MAKE) -C libft clean

fcleanlibft :
	$(MAKE) -C libft fclean
	
clean : cleanlibft
	$(RM) $(OBJS)

fclean : clean fcleanlibft
	$(RM) $(NAME)
	rm -rf a.out a.out.dSYM

re : fclean all

.PHONY : all clean fclean re libft cleanlibft fcleanlibft
