# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 09:44:16 by ysmeding          #+#    #+#              #
#    Updated: 2023/09/07 15:28:12 by ysmeding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

all:
	gcc -Wall -Wextra -Werror src/*.c libft/*.c -o cub3d MLX/libmlx42.a -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

bonus: 
	gcc -Wall -Wextra -Werror src_bonus/*.c libft/*.c -o cub3d_bonus MLX/libmlx42.a -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

mlx:
	make -C ./MLX all