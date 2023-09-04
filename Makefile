# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 09:44:16 by ysmeding          #+#    #+#              #
#    Updated: 2023/09/01 10:05:41 by ysmeding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

all:
	gcc src/*.c libft/*.c -o cub3d MLX/libmlx42.a -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

bonus: 
	gcc src_bonus/*.c libft/*.c -o cub3d_bonus MLX/libmlx42.a -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

mlx:
	make -C ./MLX all