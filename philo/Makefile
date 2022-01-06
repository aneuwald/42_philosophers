# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 19:18:55 by acanterg          #+#    #+#              #
#    Updated: 2021/12/22 19:54:31 by acanterg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/functions/ft_atoi.c \
			srcs/functions/ft_error.c \
			srcs/functions/ft_putnbr.c \
			srcs/functions/ft_putstr.c \
			srcs/functions/ft_putchar.c \
			srcs/functions/ft_strcmp.c \
			srcs/functions/ft_strlen.c \
			srcs/philosopher/checks.c \
			srcs/philosopher/init.c \
			srcs/philosopher/threads.c \
			srcs/philosopher/utils.c \
			srcs/philosopher/quit.c \
			srcs/philosopher/philosphers.c \
			srcs/philosopher/validation.c \
			srcs/philosopher/main.c



GCC		= gcc
CFLAGS	= -Wall -Wextra -Werror
FSANIT  =  -fsanitize=address -g
INCLUD	= -I includes
NAME	= philo

all : 		$(NAME)

$(NAME) :	
			@ $(GCC) $(CFLAGS) $(FSANIT) $(INCLUD) $(SRCS) -o $(NAME)

clean :
			@ rm -f $(NAME)

bonus :		all

fclean :	clean

re :		fclean all

.PHONY: 	all clean fclean re bonus test check count