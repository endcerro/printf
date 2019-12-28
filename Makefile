# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 17:54:38 by edal--ce          #+#    #+#              #
#    Updated: 2019/12/18 21:50:30 by edal--ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	src/ft_printf.c src/unsigned.c src/ft_ultoa.c src/process_types.c src/utils.c src/process_other.c src/more_utils.c
			
OBJS = $(SRCS:.c=.o)

INCL = header/

HEADER = $(INCL)ft_printf.h

CC = clang

CFLAGS = -Wall -Wextra -Werror

LIBLINK = -L./ -lftprintf

LIB = libft/

OBJLIB = $(LIB)/*.o

LIBFT = $(LIB)libft.a

all : complib $(NAME)

$(OBJS) : %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INCL) -c $< -o $@ 

$(NAME) : $(OBJS)
	ar rcs $@ $(OBJS) $(OBJLIB)

complib :
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

.PHONY : all clean fclean re complib cleanlibft fcleanlibft
