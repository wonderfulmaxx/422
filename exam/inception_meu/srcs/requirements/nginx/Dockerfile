FROM	alpine:3.16
RUN	apk update; \
	apk add nginx; \
	apk add openssl;

COPY	./conf/nginx.conf /etc/nginx/

RUN	openssl req -x509 -nodes -days 365 -subj "/C=CA/ST=QC/O=Company, Inc./CN=mydomain.com" -addext "subjectAltName=DNS:mydomain.com" -newkey rsa:2048 -keyout /etc/ssl/private/certificate.key -out /etc/ssl/certs/certificate.crt;

EXPOSE	443

#RUN	nginx -t
CMD	["nginx", "-g", "daemon off;"]
