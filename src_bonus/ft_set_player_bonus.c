/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:27:45 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 14:43:41 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

double	find_player_x(t_cub_info *info)
{
	int	i;

	i = -1;
	while (info->map[++i])
	{
		if (ft_strchr_r(info->map[i], "NSWE") != -1)
			return (ft_strchr_r(info->map[i], "NSWE") + 0.5f);
	}
	return (-1);
}

double	find_player_y(t_cub_info *info)
{
	int	i;

	i = -1;
	while (info->map[++i])
	{
		if (ft_strchr_r(info->map[i], "NSWE") != -1)
			return (i + 0.5f);
	}
	return (-1);
}

void	set_player_rot(t_player_info *player, char c)
{
	if (c == 'E')
	{
		player->xdir = 1;
		player->ydir = 0;
		player->pov = 0;
	}
	else if (c == 'N')
	{
		player->xdir = 0;
		player->ydir = -1;
		player->pov = M_PI / 2;
	}
	else if (c == 'W')
	{
		player->xdir = -1;
		player->ydir = 0;
		player->pov = M_PI;
	}
	else if (c == 'S')
	{
		player->xdir = 0;
		player->ydir = 1;
		player->pov = 3 * M_PI / 2;
	}
}

void	find_player_rot(t_player_info *player, t_cub_info *info)
{
	int	i;

	i = -1;
	while (info->map[++i])
	{
		if (ft_strchr_r(info->map[i], "NSWE") != -1)
		{
			if (ft_strchr_i(info->map[i], 'E') != -1)
				set_player_rot(player, 'E');
			else if (ft_strchr_i(info->map[i], 'N') != -1)
				set_player_rot(player, 'N');
			else if (ft_strchr_i(info->map[i], 'W') != -1)
				set_player_rot(player, 'W');
			else if (ft_strchr_i(info->map[i], 'S') != -1)
				set_player_rot(player, 'S');
		}
	}
}

void	ft_set_player(t_player_info *player, t_cub_info *info)
{
	player->xpos = find_player_x(info);
	player->ypos = find_player_y(info);
	find_player_rot(player, info);
	player->xcamera = -player->ydir;
	player->ycamera = player->xdir;
}
