#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

CC         := c++
FLAGS    := -Wall -Wextra -Werror -std=c++98
 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################


STD_SRCS	:= main_std.cpp
STD_NAME	:= std
STD_OBJS	:= ${STD_SRCS:.cpp=.o}

FT_SRCS	:= main_ft.cpp
FT_NAME	:= ft
FT_OBJS	:= ${FT_SRCS:.cpp=.o}

.cpp.o:
	@${CC} ${FLAGS} -I./includes -I./includes/utils -I./includes/tree -I./includes/iterators -c $< -o ${<:.cpp=.o} -g

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f


# ${FT_NAME}: ${FT_OBJS}
# 			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(FT_NAME) ${CLR_RMV}..."
# 			${CC} ${FLAGS} -o ${FT_NAME} ${FT_OBJS}
# 			@echo "$(GREEN)$(FT_NAME) created[0m ✔️"

# ${STD_NAME}: ${STD_OBJS}
# 			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(STD_NAME) ${CLR_RMV}..."
# 			${CC} ${FLAGS} -o ${STD_NAME} ${STD_OBJS}
# 			@echo "$(GREEN)$(STD_NAME) created[0m ✔️"

all:	ft std

ft:			$(FT_OBJS)
			@${CC} ${FLAGS} -o ${FT_NAME} ${FT_OBJS}
			@echo "$(GREEN)$(FT_NAME) created[0m ✔️"

std:		${STD_OBJS}
			@${CC} ${FLAGS} -o ${STD_NAME} ${STD_OBJS}
			@echo "$(GREEN)$(STD_NAME) created[0m ✔️"

diff:	ft std
		@./ft > ft.txt
		@./std > std.txt
		diff std.txt ft.txt

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
			@ ${RM} ft.txt std.txt

fclean:		clean
			@ $(RM) $(STD_NAME)
			@ $(RM) $(FT_NAME)
			@ $(RM) out_diff/std.txt out_diff/ft.txt
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


