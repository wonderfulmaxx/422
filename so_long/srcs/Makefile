# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 16:43:29 by tbrissia          #+#    #+#              #
#    Updated: 2022/04/01 17:32:57 by mwinter-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c	 \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_atoi.c ft_strlcat.c 	 \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c    \
			ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c    \
			ft_strtrim.c ft_split.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_striteri.c 		 \
			ft_bin_hex.c ft_putnbr_base_fd.c ft_putnbr_pr_fd.c ft_putuns_fd.c\
			ft_printf.c ft_power.c

OBJS	=	$(SRCS:.c=.o)

GCC 	=	gcc

RM		=	rm -f

FLAGS	=	-Wall -Werror -Wextra

NAME	=	libft.a

.c.o:
	@$(GCC) $(FLAGS) -c -I. $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
			@ar rcs $@ $^

all:		$(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME) a.out

re:			fclean all

.PHONY:		all clean fclean re
