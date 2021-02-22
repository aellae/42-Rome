# -*- Makefile -*-


NAME	=   libft.a
SRCS	=	ft_atoi.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_memcpy.c \
			ft_bzero.c

OBJS	= $(SRCS:.c=.o)
CC 		= gcc
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= .

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

$(NAME): ${OBJS}
	${LIBC} $(NAME) $(OBJS)

all: $(NAME)


fclean: clean
	$(RM) $(NAME) 

clean:
	$(RM) -f $(OBJS)

re: fclean all

.PHONY: all bonus clean fclean re .c.o