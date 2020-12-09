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

all : $(NAME)

.c.o: 
	$(CC) $(CFLAGS) -g -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS) 

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
