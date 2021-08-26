NAME	= do-op
SRCS	= main.c ft_putstr.c ft_atoi.c ft_putnbr.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${OBJS}
			${CC} -o ${NAME} ${OBJS}

re: 		fclean all

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY : all re clean fclean
