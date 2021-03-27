NAME_CHECKER = checker
NAME_PUSHSWAP = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
CHECKER_SRCDIR = checker_src
CHECKER_OBJDIR = .obj-checker
PUSHSWAP_SRCDIR = push_swap_src
PUSHSWAP_OBJDIR = .obj-pushswap
SHARED_SRCDIR = common
SHARED_OBJDIR = .obj-shared
EXEDIR = ./

RED=\033[0;31m
GREEN=\033[0;32m
CYAN=\033[0;36m
NC=\033[0m # No Color

SRC_CHECKER =	\
				checker.c			\
				checker_utils.c		\
				gnl.c				\
				bonusv.c			\

SRC_PUSHSWAP =	\
				push_swap.c			\
				lis.c				\
				operation.c			\
				rotation.c			\

SRC_SHARED =	\
				utils.c				\
				utils2.c			\
				libft.c				\
				libft2.c			\
				create_free_stack.c	\
				commands.c			\
				commands2.c			\



OBJ_CHECKER = $(SRC_CHECKER:%.c=$(CHECKER_OBJDIR)/%.o)
OBJ_PUSHSWAP = $(SRC_PUSHSWAP:%.c=$(PUSHSWAP_OBJDIR)/%.o)
OBJ_SHARED = $(SRC_SHARED:%.c=$(SHARED_OBJDIR)/%.o)

all: $(EXEDIR)$(NAME_CHECKER) $(EXEDIR)$(NAME_PUSHSWAP)

$(EXEDIR)$(NAME_CHECKER): $(OBJ_CHECKER) $(OBJ_SHARED) 
	@echo "${GREEN} [ + ] ${NC}Creating checker object files"
	@echo "${GREEN} [ + ] ${NC}Creating shared object files"
	@echo "${GREEN} [ + ] ${NC}Creating checker executable"
	@$(CC) $(FLAGS) $(OBJ_CHECKER) $(OBJ_SHARED) -o $(EXEDIR)$(NAME_CHECKER) \
	

$(EXEDIR)$(NAME_PUSHSWAP): $(OBJ_PUSHSWAP) $(OBJ_SHARED)
	@echo "${GREEN} [ + ] ${NC}Creating push_swap object files"
	@echo "${GREEN} [ + ] ${NC}Creating push_swap executable"
	@$(CC) $(FLAGS) $(OBJ_PUSHSWAP) $(OBJ_SHARED) -o $(EXEDIR)$(NAME_PUSHSWAP) \

$(SHARED_OBJDIR)/%.o: $(SHARED_SRCDIR)/%.c 
	@mkdir -p $(SHARED_OBJDIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(CHECKER_OBJDIR)/%.o: $(CHECKER_SRCDIR)/%.c
	@mkdir -p $(CHECKER_OBJDIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(PUSHSWAP_OBJDIR)/%.o: $(PUSHSWAP_SRCDIR)/%.c 
	@mkdir -p $(PUSHSWAP_OBJDIR)
	@$(CC) $(FLAGS) -c -o $@ $<

.PHONY: clean

clean:
	@echo "${RED} [ - ] ${NC}Deleting checker object files"
	@rm -rf $(CHECKER_OBJDIR)
	@echo "${RED} [ - ] ${NC}Deleting push_swap object files"
	@rm -rf $(PUSHSWAP_OBJDIR)
	@echo "${RED} [ - ] ${NC}Deleting shared object files"
	@rm -rf $(SHARED_OBJDIR)

fclean: clean
	@echo "${RED} [ - ] ${NC}Deleting checker executable"
	@rm -f $(EXEDIR)$(NAME_CHECKER)
	@echo "${RED} [ - ] ${NC}Deleting push_swap executable"
	@rm -f $(EXEDIR)$(NAME_PUSHSWAP)

re: fclean all

lldb: re
	gcc -g main.c -L. -lft

norm:
	norminette $(SRC) | grep -e "Error" -e "Warning" -B 1
