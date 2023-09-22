/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:12:43 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/21 13:00:13 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

//double	ft_setang(double ang);

void	move_player_front(t_cub_info *cub, t_player_info *player, int i)
{
	int	tmp[2];
	int	idx;

	tmp[0] = player->xpos + MOV_SPEED * player->xdir * i;
	tmp[1] = player->ypos + MOV_SPEED * player->ydir * i;
	if (cub->map[tmp[1]][tmp[0]] != '1' && cub->map[tmp[1]][tmp[0]] != 'D')
	{
		if (!ft_checkdiagmove(cub, player, tmp))
		{
			player->xpos += MOV_SPEED * player->xdir * i;
			player->ypos += MOV_SPEED * player->ydir * i;
			idx = 0;
			while (idx < 5)
			{
				if (cub->doordir[idx])
				{
					if (ft_dist(cub, player, idx) > 1.5)
						ft_close_door(cub, idx);
				}
				idx++;
			}
		}
	}
}

void	move_player_lateral(t_cub_info *cub, t_player_info *player, int i)
{
	int	tmp[2];
	int	idx;

	tmp[0] = player->xpos + MOV_SPEED * player->xcamera * i;
	tmp[1] = player->ypos + MOV_SPEED * player->ycamera * i;
	if (cub->map[tmp[1]][tmp[0]] != '1' && cub->map[tmp[1]][tmp[0]] != 'D')
	{
		if (!ft_checkdiagmove(cub, player, tmp))
		{
			player->xpos += MOV_SPEED * player->xcamera * i;
			player->ypos += MOV_SPEED * player->ycamera * i;
			idx = 0;
			while (idx < 5)
			{
				if (cub->doordir[idx])
				{
					if (ft_dist(cub, player, idx) > 1.5)
						ft_close_door(cub, idx);
				}
				idx++;
			}
		}
	}
}

void	move_player(t_cub_info *cub, t_player_info *player, int i)
{
	if (i == 'W')
		move_player_front(cub, player, -1);
	if (i == 'S')
		move_player_front(cub, player, 1);
	if (i == 'A')
		move_player_lateral(cub, player, -1);
	if (i == 'D')
		move_player_lateral(cub, player, 1);
}

void	rot_player(t_player_info *player, int i)
{
	rotate_z(&player->xdir, &player->ydir, ROT_SPEED * i);
	rotate_z(&player->xcamera, &player->ycamera, ROT_SPEED * i);
	player->pov += ROT_SPEED * i;
	player->pov = ft_setang(player->pov);
}

void	rot_player_mouse(t_player_info *player, int i, float vel)
{
	rotate_z(&player->xdir, &player->ydir, vel * i);
	rotate_z(&player->xcamera, &player->ycamera, vel * i);
	player->pov += vel * i;
	player->pov = ft_setang(player->pov);
}
