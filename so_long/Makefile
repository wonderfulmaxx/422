# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 18:01:43 by mwinter-          #+#    #+#              #
#    Updated: 2022/04/14 15:17:07 by mwinter-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%.o: %.c
	gcc -Wall -Werror -Wextra -Imlx -c $< -o $@

all: so_long.c
		gcc -Wall -Wextra -Werror so_long.c -Lmlx -lmlx -framework OpenGL -framework AppKit -o so_long srcs/libft.a