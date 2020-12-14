# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atinseau <atinseau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 14:00:10 by atinseau          #+#    #+#              #
#    Updated: 2020/12/14 17:49:35 by atinseau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_parsing.c \
	ft_print_hex.c \
	ft_print_str.c \
	ft_print_number.c \
	ft_printf.c \
	ft_printing.c \
	ft_printf_utils.c

OBJS = ${SRCS:.c=.o}

LIBFT = $(wildcard libft/*.o)

all : $(NAME)

.c.o: 
	$(CC) $(CFLAGS) -g -c $< -o ${<:.c=.o}

get: 
	cd libft && make all

$(NAME) : $(OBJS) get
	ar rcs $(NAME) $(OBJS) $(LIBFT)

clean : 
	rm -f $(OBJS) $(OBJSTOOL)

fclean : clean 
	rm -f $(NAME)

push : 
	git add -A 
	git commit -m "auto commit"
	git push origin main 

pull :
	make fclean
	git pull
	make re

re : fclean all
