# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 11:13:16 by mwinter-          #+#    #+#              #
#    Updated: 2022/04/09 18:29:43 by mwinter-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  push_swap.c push_swaper.c push_swaper2.c

OBJS 		= ${SRCS:.c=.o}

NAME 		= push_swap

CC 			= gcc
RM 			= rm -rf
AR 			= ar rcs
RN 			= ar rcs

CFLAGS 		= -Wall -Wextra -Werror

.c.o:
				${CC} -c $< -o ${<:.c=.o}

$(NAME): 	${OBJS}
				${CC} -o ${NAME} ${OBJS} lib42/libft.a

all:		$(NAME)

debug:		
				gcc -o push_swap.debug ${OBJS} lib42/libft.a -g

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} $(NAME)

fcleandebug:  fclean
				${RM} push_swap.debug .vscode push_swap.debug.dSYM

re:			fclean all
