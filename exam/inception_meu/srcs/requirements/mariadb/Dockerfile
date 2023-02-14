FROM	alpine:3.16
RUN	apk update; \
	apk add mariadb \
	mariadb-common \
	mariadb-client \
	mysql;

WORKDIR	/tmp
COPY	./tools/install.sh .
RUN	chmod 755 ./install.sh

ENTRYPOINT	./install.sh
