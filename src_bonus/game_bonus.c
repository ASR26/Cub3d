/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:55:36 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/25 13:13:13 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	ft_initwindow(t_window_info	*window)
{
	window->wid = WID;
	window->hei = HEI;
	window->lastclickx = -1;
	window->leftclick = 0;
	window->action = 0;
	window->button = -1;
	window->frame = 0;
	window->menu = 0;
	window->attack = 0;
	window->attack = 0;
	window->mlx = mlx_init(window->wid, window->hei, "cub3d", true);
	window->t_oc = 0;
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
	if (mlx_is_key_down(all->window->mlx, MLX_KEY_F))
		ft_fkey(all);
	mlx_mouse_hook(all->window->mlx, &ft_mlx_mousefunc, all);
	if (all->window->attack)
		ft_enable_images(all);
	all->window->frame++;
}

void	ft_delete_textures(t_all_info *all)
{
	int	i;

	mlx_delete_texture(all->draw->n_wall);
	mlx_delete_texture(all->draw->s_wall);
	mlx_delete_texture(all->draw->e_wall);
	mlx_delete_texture(all->draw->w_wall);
	if (all->draw->door)
		mlx_delete_texture(all->draw->door);
	mlx_delete_texture(all->draw->treasurec);
	mlx_delete_texture(all->draw->treasureo);
	mlx_delete_texture(all->draw->weapon);
	i = 0;
	while (i < 10)
	{
		mlx_delete_texture(all->draw->weapon_mv[i]);
		i++;
	}
}

void	ft_game(t_cub_info *info, t_player_info *player)
{
	t_window_info	window;
	t_all_info		all;
	t_draw			draw;

	(void) info;
	ft_setdraw(&draw, info);
	ft_initwindow(&window);
	all.window = &window;
	all.info = info;
	all.player = player;
	all.draw = &draw;
	window.g_img = mlx_new_image(window.mlx, WID, HEI);
	window.g_img_mm = mlx_new_image(window.mlx, M_WID, M_HEI);
	window.g_img_w = mlx_new_image(window.mlx, W_WID, W_HEI);
	window.g_img_tc = mlx_new_image(window.mlx, WID, HEI);
	ft_makeweaponimage(all.window->g_img_w, all.draw->weapon, W_WID, W_HEI);
	ft_makeweaponmvimages(&all);
	ft_angleloop(&all);
	makeimage(&window, &all);
	ft_put_images(&all);
	mlx_loop_hook(window.mlx, &ft_hook, &all);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
	ft_delete_textures(&all);
}
