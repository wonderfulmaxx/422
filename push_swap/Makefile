# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 11:13:16 by mwinter-          #+#    #+#              #
#    Updated: 2022/04/04 16:04:27 by mwinter-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  push_swap.c push_swaper.c

OBJS 		= ${SRCS:.c=.o}

NAME 		= push_swap

CC 			= gcc
RM 			= rm -f
AR 			= ar rcs
RN 			= ar rcs

CFLAGS 		= -Wall -Wextra -Werror

.c.o:
				${CC} -c $< -o ${<:.c=.o}

$(NAME): 	${OBJS}
				${CC} -o ${NAME} ${OBJS} lib42/libft.a

all:		$(NAME)

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} $(NAME)

re:			fclean all
