/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:00:07 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 15:07:48 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_move_and_image(t_all_info *all, int move)
{
	if (move == 0)
		move_player_front(all->info, all->player, 1);
	else if (move == 1)
		move_player_front(all->info, all->player, -1);
	else if (move == 2)
		move_player_lateral(all->info, all->player, -1);
	else if (move == 3)
		move_player_lateral(all->info, all->player, 1);
	else if (move == 4)
		rot_player(all->player, -1);
	else if (move == 5)
		rot_player(all->player, 1);
	ft_angleloop(all);
	makeimage(all->window, all);
}

void	ft_tabkey(t_all_info *all)
{
	if (all->window->menustr[0]->enabled)
		ft_disable_menu(all);
	else
		ft_enable_menu(all);
}

void	ft_mlx_keyfunc(mlx_key_data_t keydata, void *param)
{	
	t_all_info	*all;

	all = param;
	if (keydata.key == MLX_KEY_W)
		ft_move_and_image(all, 0);
	if (keydata.key == MLX_KEY_S)
		ft_move_and_image(all, 1);
	if (keydata.key == MLX_KEY_A)
		ft_move_and_image(all, 2);
	if (keydata.key == MLX_KEY_D)
		ft_move_and_image(all, 3);
	if (keydata.key == MLX_KEY_RIGHT)
		ft_move_and_image(all, 4);
	if (keydata.key == MLX_KEY_LEFT)
		ft_move_and_image(all, 5);
	if (keydata.key == MLX_KEY_TAB && keydata.action == 1)
		ft_tabkey(all);
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(all->window->mlx);
}