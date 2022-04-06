# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 18:01:43 by mwinter-          #+#    #+#              #
#    Updated: 2022/04/04 18:18:31 by mwinter-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

all:	$(NAME)

%.o: %.c
	@$gcc -Wall -Werror -Wextra -Imlx -c $< -o $@

$(NAME): so_long.c
		gcc so_long.c -Lmlx-lmlx -framework OpenGL -framework AppKit -o so_long ./srcs/libft.a