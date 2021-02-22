NAME			= miniRT
BONUS_NAME		= miniRT_bonus

CSRCS_LIST		= \
					create_object.c \
					create_object_bonus.c \
					create_object_texture.c \
					create_utils.c \
					get_info.c \
					read.c \
					read_utils.c \
					skip.c \
					read_2.c

ISRCS_LIST		= \
					pl_and_sq.c \
					tr.c \
					ray_trace.c \
					solid_figure.c \
					normal.c \
					shadow.c \
					utils.c \
					bonus.c

COSRCS_LIST		= \
					colors.c \
					colors_bonus.c \
					utils.c \
					texture.c

USRCS_LIST		= \
					bonus_utils.c \
					rot_stuff.c \
					save_image.c \
					free.c \
					maths_double.c \
					maths_point.c

KSRCS_LIST		= \
				keyboard.c \
				key_objects.c \
				key_mouse.c \
				key_utils.c

WSRCS_LIST		= \
				make_window.c \
				mlx_functions.c

SRCS			= $(addprefix ${CFOLDER}/, ${CSRCS_LIST}) \
				 $(addprefix ${IFOLDER}/, ${ISRCS_LIST}) \
 				 $(addprefix ${COFOLDER}/, ${COSRCS_LIST}) \
				 $(addprefix ${UFOLDER}/, ${USRCS_LIST}) \
				 $(addprefix ${KFOLDER}/, ${KSRCS_LIST}) \
				 $(addprefix ${WFOLDER}/, ${WSRCS_LIST}) \
				main.c \

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
CFOLDER			= Check_file
IFOLDER			= Intersection
COFOLDER		= Colors
UFOLDER			= Utils
KFOLDER			= Keycode
WFOLDER			= Window

LIBFT 			= libft
MLX 			= mlx

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
LFLAGS			= -L libft -lft

METAL_MLX		= libmlx.dylib -framework Metal -framework AppKit

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -s -C $(MLX)
				@mv $(MLX)/libmlx.dylib .
				@make -s -C $(LIBFT)
				@$(CC) $(CFLAGS) $(LFLAGS) $(METAL_MLX) -I $(HEADER) $(OBJS) -o $(NAME)

%.o: %.c
				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

bonus:			$(OBJS)
				@make -s -C $(MLX)
				@mv $(MLX)/libmlx.dylib .
				@make -s -C $(LIBFT)
				@$(CC) $(CFLAGS) $(LFLAGS) $(METAL_MLX) -I $(HEADER) $(OBJS) -o $(BONUS_NAME)

clean:
				@$(RM) $(OBJS)
				@make clean -C $(MLX)
				@make clean -C $(LIBFT)

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(BONUS_NAME)
				@$(RM) libmlx.dylib
				@$(RM) img.bmp
				@make fclean -C $(LIBFT)

re:				fclean all

.PHONY: 		all fclean clean re
