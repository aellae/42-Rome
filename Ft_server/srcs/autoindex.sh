# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    autoindex.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etaranti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 08:38:35 by etaranti          #+#    #+#              #
#    Updated: 2021/01/29 08:38:40 by etaranti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
if grep -q "autoindex on" /etc/nginx/sites-available/default
then 
    sed -i 's/autoindex on/autoindex off/' /etc/nginx/sites-available/default
    echo "autoindex off"
    service nginx restart
else
    sed -i 's/autoindex off/autoindex on/' /etc/nginx/sites-available/default
    echo "autoindex on"
    service nginx restart

fi
