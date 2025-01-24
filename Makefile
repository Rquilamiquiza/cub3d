# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joandre <joandre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 10:21:32 by joandre           #+#    #+#              #
#    Updated: 2025/01/23 21:02:36 by joandre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d
SRC_DIR = sources
SRC = hovers.c main.c window.c valid_map.c analizer_map.c player.c screen.c
LIBFT_DIR = libft
GETNEXTLINE_DIR = get_next_line
GETNEXTLINE = $(GETNEXTLINE_DIR)/get_next_line.a
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx -lXext -lX11 -lm -lz
OBJ = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(GETNEXTLINE)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(GETNEXTLINE) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GETNEXTLINE):
	make -C $(GETNEXTLINE_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(GETNEXTLINE_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(GETNEXTLINE_DIR) fclean

re: fclean all


