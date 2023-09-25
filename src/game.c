/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:45:44 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/25 09:54:21 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_initwindow(t_window_info	*window)
{
	window->wid = WID;
	window->hei = HEI;
	window->frame = 0;
	window->menu = 0;
	window->mlx = mlx_init(window->wid, window->hei, "cub3d", true);
}

void	ft_hook(void *arg)
{
	t_all_info	*all;

	all = arg;
	mlx_key_hook(all->window->mlx, &ft_mlx_keyfunc, all);
	if (mlx_is_key_down(all->window->mlx, MLX_KEY_W))
		ft_move_and_image(all, 0);
	if (mlx_is_key_down(all->window->mlx, MLX_KEY_S))
		ft_move_and_image(all, 1);
	if (mlx_is_key_down(all->window->mlx, MLX_KEY_A))
		ft_move_and_image(all, 2);
	if (mlx_is_key_down(all->window->mlx, MLX_KEY_D))
		ft_move_and_image(all, 3);
	if (mlx_is_key_down(all->window->mlx, MLX_KEY_RIGHT))
		ft_move_and_image(all, 4);
	if (mlx_is_key_down(all->window->mlx, MLX_KEY_LEFT))
		ft_move_and_image(all, 5);
	if (mlx_is_key_down(all->window->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(all->window->mlx);
	all->window->frame++;
}

void	ft_delete_textures(t_all_info *all)
{
	mlx_delete_texture(all->draw->n_wall);
	mlx_delete_texture(all->draw->s_wall);
	mlx_delete_texture(all->draw->e_wall);
	mlx_delete_texture(all->draw->w_wall);
}

void	ft_game(t_cub_info *info, t_player_info *player)
{
	t_window_info	window;
	t_all_info		all;
	t_draw			draw;

	ft_setdraw(&draw, info);
	ft_initwindow(&window);
	all.window = &window;
	all.info = info;
	all.player = player;
	all.draw = &draw;
	window.g_img = mlx_new_image(window.mlx, WID, HEI);
	makeimage(&window, &all);
	ft_put_images(&all);
	mlx_loop_hook(window.mlx, &ft_hook, &all);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
	ft_delete_textures(&all);
}
