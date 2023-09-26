/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:00:07 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/25 09:54:29 by ysmeding         ###   ########.fr       */
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
	if (keydata.key == MLX_KEY_TAB && keydata.action == 1)
		ft_tabkey(all);
}
