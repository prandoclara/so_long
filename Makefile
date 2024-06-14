NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.a

CC = cc
INCLUDES = -I/usr/include -I$(MLX_DIR) -I./$(LIBFT_DIR)/include -I./include
CFLAGS = -Wall -Wextra -Werror -g3 $(INCLUDES)

SRCS_DIR = ./srcs
OBJS_DIR = ./obj
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

MLX_FLAGS = -L$(MLX_DIR) -Lmlx -lmlx -L/usr/X11/lib -lX11 -lXext
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(MLX) :
	@$(MAKE) -sC $(MLX_DIR)

clean:
	@rm -f $(OBJS_DIR)/*.o
	@rmdir $(OBJS_DIR)
	@$(MAKE) -sC $(LIBFT_DIR) clean 
	@$(MAKE) -sC $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -sC $(LIBFT_DIR) fclean
	$(MAKE) -sC $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
