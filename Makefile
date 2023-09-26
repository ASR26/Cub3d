# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 09:44:16 by ysmeding          #+#    #+#              #
#    Updated: 2023/09/25 13:13:34 by ysmeding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

MLX = ./MLX/libmlx42.a

MLX_PATH = ./MLX

LIBFT_PATH = ./libft

SRC_DIR = src

OBJ_DIR = obj

SRC_BONUS_DIR = src_bonus

OBJ_BONUS_DIR = obj_bonus

SRC_FILES = src/arr_utils.c \
			src/calc_dist.c \
			src/check_dup.c \
			src/cub3d.c \
			src/distance.c \
			src/distance_crossings.c \
			src/distance_init.c \
			src/distance_utils.c \
			src/errorfunc.c \
			src/ft_freefunc.c \
			src/ft_getstr.c \
			src/ft_parse_check_and_get_func.c \
			src/ft_parse_checkfunc.c \
			src/ft_parse_map.c \
			src/ft_parse_scene.c \
			src/ft_parse_utils.c \
			src/ft_set_player.c \
			src/game.c \
			src/game_enable_image.c \
			src/game_image.c \
			src/game_key.c \
			src/game_putpixels.c \
			src/game_utils.c \
			src/matrix.c \
			src/movement.c \
			src/parse_scene1.c \
			src/str_utils.c \
			src/textures.c \

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

SRC_BONUS_FILES =	src_bonus/arr_utils_bonus.c \
					src_bonus/calc_dist_bonus.c \
					src_bonus/check_dup_bonus.c \
					src_bonus/cub3d_bonus.c \
					src_bonus/distance_bonus.c \
					src_bonus/distance_crossings_bonus.c \
					src_bonus/distance_init_bonus.c \
					src_bonus/distance_treasure_bonus.c \
					src_bonus/distance_treasure_utils_bonus.c \
					src_bonus/distance_utils_bonus.c \
					src_bonus/errorfunc_bonus.c \
					src_bonus/ft_freefunc_bonus.c \
					src_bonus/ft_getstr_bonus.c \
					src_bonus/ft_parse_check_and_get_func_bonus.c \
					src_bonus/ft_parse_checkfunc_bonus.c \
					src_bonus/ft_parse_map_bonus.c \
					src_bonus/ft_parse_scene_bonus.c \
					src_bonus/ft_parse_utils_bonus.c \
					src_bonus/ft_set_player_bonus.c \
					src_bonus/game_bonus.c \
					src_bonus/game_cursor_bonus.c \
					src_bonus/game_doortreasure_utils_bonus.c \
					src_bonus/game_enable_image_bonus.c \
					src_bonus/game_image_bonus.c \
					src_bonus/game_image_minimap_bonus.c \
					src_bonus/game_key_bonus.c \
					src_bonus/game_putpixels_bonus.c \
					src_bonus/game_treasure_bonus.c \
					src_bonus/game_utils_bonus.c \
					src_bonus/matrix_bonus.c \
					src_bonus/movement_bonus.c \
					src_bonus/movement_utils_bonus.c \
					src_bonus/parse_scene1_bonus.c \
					src_bonus/str_utils_bonus.c \
					src_bonus/textures_bonus.c \

OBJ_BONUS_FILES = $(patsubst $(SRC_BONUS_DIR)/%.c,$(OBJ_BONUS_DIR)/%.o,$(SRC_BONUS_FILES))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES) 
	@ $(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME) $(MLX) -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS_FILES)
	@ $(CC) $(CFLAGS) $(OBJ_BONUS_FILES) $(LIBFT) -o $(NAME_BONUS) $(MLX) -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

$(LIBFT):
	@ make -C $(LIBFT_PATH) all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

libclean:
	@ make -C $(LIBFT_PATH) clean

libfclean:
	@ make -C $(LIBFT_PATH) fclean

mlxclean:
	@ make -C $(MLX_PATH) clean

mlxfclean:
	@ make -C $(MLX_PATH) fclean

$(MLX):
	@ make -C ./MLX all

clean: libclean
	@ rm -rf $(OBJ_DIR)
	@ rm -rf $(OBJ_BONUS_DIR)

fclean: clean libfclean
	@ rm -rf $(NAME)
	@ rm -rf $(NAME_BONUS)

re: fclean all

rebonus: fclean bonus

.PHONY: re clean fclean mlxclean mlxfclean libclean libfclean all bonus