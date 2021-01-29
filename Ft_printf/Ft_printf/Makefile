# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etaranti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 09:43:51 by etaranti          #+#    #+#              #
#    Updated: 2021/01/18 09:43:53 by etaranti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   libftprintf.a
SRCS	=	base_case.c \
			ft_printf.c \
			hex_case.c \
			utils.c \
			check_base.c \
			init_flags.c \
			print.c 


OBJS	= $(SRCS:.c=.o)
CC 		= gcc
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= .
LIBFT	= ./libft/libft.a

%.o: %.c $(LIBFT)
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCS}


$(NAME): ${OBJS} $(LIBFT)
	cp	$(LIBFT) $(NAME)
	${LIBC} $(NAME) $(OBJS)


all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME)

clean:
	make clean -C ./libft
	$(RM) -f $(OBJS) $(OBJS_B)

re: fclean all

.PHONY: all bonus clean fclean re .c.o


