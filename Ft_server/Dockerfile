# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etaranti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 08:29:40 by etaranti          #+#    #+#              #
#    Updated: 2021/01/29 08:30:52 by etaranti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# debian è il sistema operativo che uso per il mio contenitore 
# i comandi che eseguirò verranno eseguiti in quel contenitore
# sto usando delle risorse del computer per simulare un altro computer (questo è il contenitore)
FROM debian:buster

# upgrado debian
RUN apt-get update
RUN apt-get upgrade -y

# mi installo wget che è un programma che serve a scaricare contenuti dal web-sever
RUN apt-get -y install wget

# installo nginx (web server open source, serve per non diminuire le prestazioni della macchina) 
RUN apt-get -y install nginx

#installo mardiadb (sistema di gestione di basi di sati, consente alla creazione, manipolazione di database)
RUN apt-get -y install mariadb-server

COPY ./srcs/default /etc/nginx/sites-available/default

# installo php
RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

# installo phpmyadmin (è un'applicazione, che consente di aministrare mariadb,
# gestisce i permessi, crea database, tabelle e esegue operazioni di ottimizzazione)
WORKDIR /var/www/html/
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin
COPY ./srcs/config.inc.php phpmyadmin

# installo wordpress (piattaforma software e content management system,
# è un programma che consente la creazione e 
# distribuzione di un server formato da contenuti testuali o multimediali)
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz
COPY ./srcs/wp-config.php /var/www/html/wordpress

# gestione dell'autoindex (cd .. cd .. etc bash autoindex.sh)
COPY ./srcs/autoindex.sh /tmp/

# creo e certifico una chiave ssl
RUN openssl req -x509 -nodes -days 365 -subj "/C=IT/ST=Italy/L=Rome/O=luiss/OU=42rome/CN=etaranti" \
	-newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt

RUN chown -R www-data:www-data *
RUN chmod -R 755 /var/www/*
COPY ./srcs/init.sh /tmp/
CMD bash /tmp/init.sh
