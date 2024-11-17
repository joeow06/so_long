LIBFT = libft/libft.a
NAME = so_long

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC = so_long.c error_handle.c map_checker.c to_array_map.c check_valid_path.c free.c draw_map.c \
		hooks.c moves.c close_game.c
INC = so_long.h
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Detect platform and set flags dynamically
ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	INCLUDES = -I/opt/X11/include -Imlx
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(shell uname).a

RM = rm -rf

# Rule to create the final executable
all: $(MLX_LIB) $(NAME)

# Linking the final executable
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

# Rule to compile .o files from .c files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build MLX library
$(MLX_LIB):
	@make -C $(MLX_DIR)

# Build libft
$(LIBFT):
	$(MAKE) -C ./libft

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C ./libft clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
