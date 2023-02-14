SRCS		:=	./srcs/

DOCKER_FILES	:= $(shell docker ps -a -q)
DOCKER_IMAGES	:= $(shell docker images -aq)

compose:
	cd ./srcs && docker compose up

rm:	
	@ echo 'Clean up remnants docker files'
	@ -docker rm $(DOCKER_FILES)
rmi:
	@ echo 'Clean up docker images'
	@ -docker rmi -f $(DOCKER_IMAGES)

fclean: rm rmi
