NAME	= ft_cat
SRCS	= main.c ft_putstr.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

re: 		fclean all

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY : all re clean fclean
