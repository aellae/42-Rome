# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 10:24:03 by etaranti          #+#    #+#              #
#    Updated: 2021/03/08 17:25:24 by ade-feli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

NAME	=   libft.a

SRCS	=	\
			spaces.c \
			welcome.c	\
			new.c	\
			charjoin.c	\
			ft_strcmp.c	\
			free.c \
			ft_strlen.c \
			add_str.c \
			ft_itoa.c	\
			ft_strcpy.c \
			ft_split.c	\
			ft_strdup.c	\
			ft_atoi.c	\
			ft_strjoin.c \
			ft_isprint.c

HEADER	=	libft.h

OBJS	=	$(SRCS:.c=.o)
CC 		=	gcc
RM		=	rm -f
LIBC	=	ar -rcs
FLAGS	=	-Wall -Wextra -Werror
INCS	= 	.

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

all:		$(NAME)

$(NAME):	${OBJS}
			@echo "\n\n\033[0;32mCompiling libft..."
			@$(LIBC) $(NAME) $^
			@ranlib $(NAME)
			@echo "\033[0m"

%.o: %.c
			@printf "\033[0;33mGenerating libft objects... %-33.33s\r" $@
			@${CC} ${CFLAGS} -c $< -o $@

clean:
			@rm -f $(OBJS)

fclean: clean
			@rm -f $(NAME)

re: fclean all

norm:
			norminette $(SRCS) $(HEADER)

.PHONY: all clean fclean re norm
