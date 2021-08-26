#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jule-mer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 10:55:25 by jule-mer          #+#    #+#              #
#    Updated: 2021/08/22 23:31:44 by jule-mer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = ft_check_dict2.c ft_free.c ft_in_struct_2.c ft_strs_2.c print.c \
		  count_occ_types.c ft_check_dict.c ft_compare_dict.c ft_in_struct.c \
		  ft_strs.c main.c read.c
OBJS    = ${SRCS:.c=.o}
INCLU	= ft.h
NAME    = rush-02
CC		= cc
CFLAGS	= -Wall #-Werror -Wextra
RM		= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
			${CC} -I ${INCLU} -o ${NAME} ${OBJS}

all:        ${NAME}

clean:
	${RM} ${OBJS}

fclean:        clean
	${RM} ${NAME}

re:            fclean all

.PHONY:        all clean fclean re
