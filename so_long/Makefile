# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 18:01:43 by mwinter-          #+#    #+#              #
#    Updated: 2022/04/10 16:34:14 by mwinter-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%.o: %.c
	gcc -Wall -Werror -Wextra -Imlx -c $< -o $@

all: so_long.c
		gcc so_long.c -Lmlx -lmlx -framework OpenGL -framework AppKit -o so_long srcs/libft.a