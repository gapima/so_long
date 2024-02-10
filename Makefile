
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

INC = ./include
LIBFT = ./lib/libft
LIBMLX = ./lib/MLX42

HEADERS = -I $(INC) -I $(LIBMLX)/include
LIBS = ./lib/libft/libft.a $(LIBMLX)/build/libmlx42.a #-ldl -lglfw -pthread -lm

OBJECTSDIR = obj/

FILES = src/main.c src/validmaps.c

OBJS = $(FILES:%.c=%.o)

all: libmlx create_mkdir $(NAME)

create_mkdir:
	@mkdir -p $(OBJECTSDIR)

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

.PHONY: all clean fclean re