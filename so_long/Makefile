NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux

LIBFT_DIR = libft

SRC_FILES = src/so_long.c 				\
			gnl/get_next_line.c 		\
			gnl/get_next_line_utils.c 	\
			src/move.c 					\
			src/utils.c 				\
			src/window.c 				\
			src/map_check.c 			\
			src/free.c					\
			src/set_map.c          		

LIBFT_LIB = $(LIBFT_DIR)/libft.a

OBJ_FILES = $(SRC_FILES:.c=.o)

MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJ_FILES) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lX11 -lXext -o $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ_FILES)
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX_LIB)
	rm -f $(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re