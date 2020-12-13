# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atinseau <atinseau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 14:00:10 by atinseau          #+#    #+#              #
#    Updated: 2020/12/13 14:00:11 by atinseau         ###   ########.fr        #
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
	ft_printf_utils.c \

OBJS = ${SRCS:.c=.o}

OBJS_LIBFT = libft/*.o

all : $(NAME)

.c.o: 
	$(CC) $(CFLAGS) -g -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS) 
	ar rcs $(NAME) $(OBJS) $(OBJS_LIBFT) 

clean : 
	rm -f $(OBJS) 

compil:
	gcc ${SRCS} main.c -L ../libft -l ft 

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
