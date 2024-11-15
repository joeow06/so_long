LIBFT = libft/libft.a
NAME = so_long

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC = so_long.c error_handle.c map_checker.c to_array_map.c check_valid_path.c free.c set_images.c draw_map.c moves.c
INC = so_long.h
#OBJ = $(OBJ_DIR)/$(SRC:.c=.o)
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)


CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -I$(INC_DIR) -I/opt/X11/include -Imlx -Lmlx -lmlx \
            -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
RM = rm -rf

# Rule to create the final executable
all: $(NAME)

# Linking the final executable
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

# Create .o from .c file, "|" separates normal dependencies from order-only
# prerequisites. In this case, $(OBJ_DIR) is an order-only prerequisite,
# meaning that Make ensures the object directory is created, but it doesn't
# affect the actual dependency check for the .c files

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I/opt/X11/include -c $< -o $@

# Build libft
$(LIBFT):
	$(MAKE) -C ./libft

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re

