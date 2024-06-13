NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.a

CC = cc
INCLUDES = -I/usr/include -I$(MLX_DIR) -I./$(LIBFT_DIR)/include -I./include
CFLAGS = -Wall -Wextra -Werror -g3 $(INCLUDES)

SRCS_DIR = ./srcs
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -L$(MLX_DIR) -Lmlx -lmlx -L/usr/X11/lib -lX11 -lXext
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(MLX) :
	@$(MAKE) -sC $(MLX_DIR)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -sC $(LIBFT_DIR) clean 
	@$(MAKE) -sC $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -sC $(LIBFT_DIR) fclean
	$(MAKE) -sC $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
