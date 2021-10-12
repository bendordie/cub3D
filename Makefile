# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshells <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 22:06:44 by cshells           #+#    #+#              #
#    Updated: 2021/02/12 20:10:46 by cshells          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = main.c \
	  ft_add_new_sprite.c \
	  ft_check_extension.c \
	  ft_clear_spr_data.c \
	  ft_count_sprites.c \
	  ft_create_spr_struct.c \
	  ft_data_processing.c \
	  ft_draw_ceil.c \
	  ft_draw_floor.c \
	  ft_draw_image.c \
	  ft_draw_sprites.c \
	  ft_draw_walls.c \
	  ft_error.c \
	  ft_find_player.c \
	  ft_find_sprites.c \
	  ft_get_rgb_color.c \
	  ft_get_tex_color.c \
	  ft_limit_angle.c \
	  ft_list_clear.c \
	  ft_make_map.c \
	  ft_map_validation.c \
	  ft_map_valid_functions.c \
	  ft_mlx_pixel_put.c \
	  ft_mock_raycasting.c \
	  ft_move_back.c \
	  ft_move_forward.c \
	  ft_move_left.c \
	  ft_move_right.c \
	  ft_parse_map.c \
	  ft_raycasting.c \
	  ft_read_map.c \
	  ft_rework_map.c \
	  ft_set_ceil_floor_color.c \
	  ft_set_resolution.c \
	  ft_set_textures.c \
	  ft_sort_sprites.c \
	  ft_str_free.c \
	  ft_str_isdigit.c \
	  ft_take_screenshot.c \
	  ft_write_player_data.c \

OBJ = $(SRC:.c=.o)

TAGS = -Wall -Wextra -Werror

CC = gcc -g

MLX = libmlx.dylib -framework OpenGL -framework AppKit

RM = rm -rf

SRC_LIB = libft/*.c

LIBFT_PATH  = libft

LIBS = libft/libft.a

GNL = gnl/get_next_line.c

all:	 $(NAME)

$(NAME): $(SRC) $(LIBS) $(OBJ) cub.h
	$(CC) $(TAGS) $(MLX) $(LIBS) $(OBJ) $(GNL) -o $(NAME)

$(LIBS): $(SRC_LIB)
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C $(LIBFT_PATH) bonus

clean: 
	#@$(MAKE) -C mlx clean
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
