SRCS = philosopher.c launcher.c init.c utils.c
CFLAGS = -Werror -Wall -Wextra 

all:
	gcc $(SRCS) -o philosopher -g

extern:
	gcc -pthread $(SRCS) -o philosopher

clean:
	rm -f *.o

fclean : clean 
	rm -f philosopher

re: fclean all