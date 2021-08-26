SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

all:		${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

re: 		fclean all

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY : all re clean fclean
