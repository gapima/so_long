
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Wunreachable-code -Ofast
RM = rm -f

INC = ./include
LIBFT = ./lib/libft
LIBMLX = ./lib/MLX42

HEADERS = -I $(INC) -I $(LIBMLX)/include
LIBS = ./lib/libft/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

FILES = src/main.c src/actions_moves.c src/hooks_map.c src/paint_objects.c src/paint_player.c \
			src/start_game.c src/validmaps.c src/free_map.c src/memory.c src/floodfill.c \
			src/exit_error.c src/init_objects.c

OBJS = $(FILES:%.c=%.o)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS)	-c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "SUCCESS!!"

clean:
	@rm -rf $(OBJS)
	@make clean -C lib/libft
	@rm -rf $(LIBMLX)/build

fclean: clean
	@make fclean -C lib/libft
	@rm -rf $(LIBMLX)/build	
	@$(RM) $(NAME)

re: fclean all

val:
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=codam.sup --track-origins=yes --log-file=log ./$(NAME) maps/map_tiny.ber

.PHONY: all clean fclean re