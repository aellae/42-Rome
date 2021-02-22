NAME		=	libasm.a

CC			=	gcc

CC_FLAGS	=	-Wall -Wextra -Werror

NASM		=	nasm

NASM_FLAGS	=	-f macho64

SRCSF		=	ft_strlen.s	\
			   	ft_strcpy.s	\
				ft_strcmp.s	\
				ft_write.s	\
				ft_read.s 	\
				ft_strdup.s

BONUSF		=	ft_atoi_base_bonus.s 		\
				ft_list_size_bonus.s		\
				ft_list_push_front_bonus.s	\
				ft_list_sort_bonus.s		\
				ft_list_remove_if_bonus.s 	

SRCSDIR		=	srcs/

BONUSDIR		=	srcs_bonus/

SRCS		=	$(addprefix $(SRCSDIR),$(SRCSF))
BONUS 		=	$(addprefix $(BONUSDIR),$(BONUSF))

INDIR		=	includes/

OBJS		=	$(SRCS:.s=.o)
OBJS_BONUS	=	$(BONUS:.s=.o)

%.o:			%.s
				$(NASM) $(NASM_FLAGS) -I${INDIR} $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				rm -rf $(OBJS) $(OBJS_BONUS) 

fclean:			clean
				rm -rf $(NAME)	*.txt a.out test

re:				fclean $(NAME)

bonus:			$(NAME) $(OBJS_BONUS)
				ar rcs $(NAME) $(OBJS_BONUS)

test:			$(NAME)		
				$(CC) $(CC_FLAGS) $(NAME) -I includes/libasm.h  tester/main.c -o test
				./test

testbonus:		bonus
				$(CC) $(CC_FLAGS) $(NAME) -I$(INDIR)  tester/main_bonus.c -o test
				./test bonus

.PHONY:			clean fclean re bonus test
