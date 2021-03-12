
NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes/ -I libft/

LIBFT = -L libft -lft

HEADER = minishell.h

BUILTINS	=	\
					echo			\
					pwd 			\
					cd 				\
					env				\
					unset			\
					export 			\

PARSING		=	\
					get_input		\
					save_commands	\
					save_list		\
					save_found_sym	\
					save_variable 	\
					history			\
					arrow			\

TOOLS 		=	\
					execute 		\
					utils			\
					utils2			\
					get_input_utils	\

SRC = 	$(addsuffix .c, $(addprefix srcs/builtins/, $(BUILTINS))) \
		$(addsuffix .c, $(addprefix srcs/parsing/, $(PARSING))) \
		$(addsuffix .c, $(addprefix srcs/tools/, $(TOOLS))) \
		main.c

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@make -C libft/
	@echo "\033[0;32mCompiling minishell..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "\n\033[0;32mDone!"
	@echo "\033[0m"

%.o: %.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\n\033[0;32mDone!\n"
	@echo "\033[0m"

fclean:
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C libft/
	@echo "\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\n\033[0;32mDone!"
	@echo "\033[0m"

	

re: fclean all

test: all
	./minishell

norm:
	norminette $(SRC)

.PHONY: clean fclean re test norm
