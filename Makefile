# VARIABLE
NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS =  -L mlx -l mlx -framework OpenGL -framework Appkit

RM = rm -rf

# FDF
SRCS = assert_file.c bresenham.c draw_image.c draw_map.c error.c free.c hook.c image_event.c \
		main.c pixel.c read_file.c rotate_axis.c set_coordinate.c utils.c
SRCS_DIR = src/fdf/
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))

# LIBFT
LIBFT_DIR = src/libft/
LIBFT_A = $(addprefix $(LIBFT_DIR), libft.a)

# MLX
MLX_DIR = minilibx/
MLX_PATH = $(addprefix, $(MLX_DIR), libmlx.a)

INCS = includes/
OBJS = $(SRCS_PATH:.c=.o)

ifdef sanitize
	CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
endif

%.o : %.c
	@echo "$(YELLOW) *** Generating object files ... *** $(DEFAULT)"
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS) -I$(LIBFT_DIR)

all : $(NAME)
	@echo "$(GREEN) *** Project Ready! *** $(DEFAULT)"

$(NAME) : $(OBJS)
	@echo "$(GREEN) *** Compiling fdf ... *** $(DEFAULT)"
	make -C src/libft
	make -C minilibx
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A)
	@echo "$(GREEN) *** Compile Done!! *** $(DEFAULT)"

clean :
	@echo "$(RED) *** Deleting objects ... *** $(DEFAULT)"
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	@echo "$(RED) *** Deleeting executable ... *** $(DEFAULT)"
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re :
	make fclean
	make all

bonus : 
	@echo "$(GREEN) *** Bonus Compiling ... *** $(DEFAULT)"
	make all

sanitize :
	make sanitize=1 re

.PHONY : all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m