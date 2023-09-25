/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:16:21 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/25 13:15:21 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

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
	else if (move == 6)
		ft_opendoor(all);
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

void	ft_fkey(t_all_info *all)
{
	if (all->window->attack == 0)
	{
		all->window->attack = 1;
		all->window->attackbegin = all->window->frame;
		ft_enable_images(all);
	}
}

void	ft_mlx_keyfunc(mlx_key_data_t keydata, void *param)
{	
	t_all_info	*all;

	all = param;
	if (keydata.key == MLX_KEY_E && keydata.action == 1)
		ft_move_and_image(all, 6);
	if (keydata.key == MLX_KEY_TAB && keydata.action == 1)
		ft_tabkey(all);
}
