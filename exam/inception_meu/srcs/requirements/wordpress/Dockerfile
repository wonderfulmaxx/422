FROM	alpine:3.16
RUN	apk update; \
	apk add openrc; \
	apk add php8 \
	php8-fpm \
	php8-common \
	php8-mysqli \
	php8-curl \
	php8-fileinfo \
	php8-json \
	php8-mbstring \
	php8-xml \
	php8-zip \
	php8-gd \
	php8-soap \
	php8-pdo;

COPY	./conf/www.conf /etc/php8/php-fpm.d/www.conf
COPY	./conf/php.ini /etc/php8/php.ini

CMD	php-fpm8 -F
