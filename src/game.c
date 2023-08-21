/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:55:36 by ysmeding          #+#    #+#             */
/*   Updated: 2023/08/18 11:44:46 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_initwindow(t_window_info	*window)
{
	window->wid = 1800;
	window->hei = 1080;
	window->mlx = mlx_init(window->wid, window->hei, "cub3d", true);
}

void	ft_hook(void *arg)
{
	(void)arg;
}

void	ft_game(t_cub_info *info)
{
	//t_player_info	player;
	t_window_info	window;
	t_all_info		all;

	(void) info;
	ft_initwindow(&window);
	all.window = &window;
	//all.player = &player;
	mlx_loop_hook(window.mlx, &ft_hook, &all);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
}