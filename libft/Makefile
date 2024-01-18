# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gapima <gapima@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 19:28:06 by gapima            #+#    #+#              #
#    Updated: 2024/01/18 17:22:30 by gapima           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../include
RM = rm -f
FILES = ft_strlen.c ft_strjoin.c ft_strchr.c ft_strncmp.c get_next_line.c \
			ft_printf.c print_char.c print_str.c print_ptr.c print_nbr.c \
			print_unint.c print_hex.c ft_itoa.c ft_calloc.c ft_strlcpy.c
OBJS = $(FILES:.c=.o)

all: $(NAME)
	@echo "libft is ready!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re