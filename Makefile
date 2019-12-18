# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 17:54:38 by edal--ce          #+#    #+#              #
#    Updated: 2019/12/18 17:54:39 by edal--ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = src/ft_printf.c src/ft_process_flags.c src/unsigned.c src/ft_printf_utils.c src/ultoa.c
			
OBJS = $(SRCS:.c=.o)

INCL = header/

HEADER = $(INCL)ft_printf.h

CC = gcc

CFLAGS = -Werror -Wall -Wextra

LIBLINK = -L./ -lftprintf

LIB = libft/

OBJLIB = $(LIB)/*.o

LIBFT = $(LIB)libft.a

all : complib $(NAME)

$(OBJS) : %.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -I $(INCL) -c $< -o $@ 

$(NAME) : $(OBJS)
	@ar rcs $@ $(OBJS) $(OBJLIB)

complib :
	@$(MAKE) -C libft all

cleanlibft :
	@$(MAKE) -C libft clean

fcleanlibft :
	@$(MAKE) -C libft fclean

#clean : echoCLEAN cleanlibft	
clean : cleanlibft
	@$(RM) $(OBJS)

#fclean : clean echoFCLEAN fcleanlibft
fclean : clean fcleanlibft
	@$(RM) $(NAME)
	@rm -rf a.out a.out.dSYM

re : fclean all

.PHONY : all clean fclean re complib cleanlibft fcleanlibft
