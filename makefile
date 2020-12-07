NAME = libftprintf.a

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

SRCS = *.c

OBJS = ${SRCS:.c=.o}

all : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -g -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS) 

clean : 
	rm -f $(OBJS) 

fclean : clean 
	rm -f $(NAME)

re : fclean all
