/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:12:43 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 15:16:51 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_checkdiagmove(t_cub_info *cub, t_player_info *player, int tmp[2])
{
	if (ft_fl(tmp[0]) == ft_fl(player->xpos) + 1)
	{
		if (((ft_fl(tmp[1]) == ft_fl(player->ypos) + 1) && \
		(cub->map[ft_fl(player->ypos)][ft_fl(player->xpos) + 1] == '1' && \
		cub->map[ft_fl(player->ypos) + 1][ft_fl(player->xpos)] == '1')) || \
		((ft_fl(tmp[1]) == ft_fl(player->ypos) - 1) && \
		(cub->map[ft_fl(player->ypos) - 1][ft_fl(player->xpos)] == '1' && \
		cub->map[ft_fl(player->ypos)][ft_fl(player->xpos) + 1] == '1')))
			return (-1);
	}
	else if (ft_fl(tmp[0]) == ft_fl(player->xpos) - 1)
	{
		if (((ft_fl(tmp[1]) == ft_fl(player->ypos) + 1) && \
		(cub->map[ft_fl(player->ypos)][ft_fl(player->xpos) - 1] == '1' && \
		cub->map[ft_fl(player->ypos) + 1][ft_fl(player->xpos)] == '1')) || \
		((ft_fl(tmp[1]) == ft_fl(player->ypos) - 1) && \
		(cub->map[ft_fl(player->ypos) - 1][ft_fl(player->xpos)] == '1' && \
		cub->map[ft_fl(player->ypos)][ft_fl(player->xpos) - 1] == '1')))
			return (-1);
	}
	return (0);
}

void	move_player_front(t_cub_info *cub, t_player_info *player, int i)
{
	int	tmp[2];

	tmp[0] = player->xpos + MOV_SPEED * player->xdir * i;
	tmp[1] = player->ypos + MOV_SPEED * player->ydir * i;
	if (cub->map[tmp[1]][tmp[0]] != '1' && cub->map[tmp[1]][tmp[0]] != 'D')
	{
		if (!ft_checkdiagmove(cub, player, tmp))
		{
			player->xpos += MOV_SPEED * player->xdir * i;
			player->ypos += MOV_SPEED * player->ydir * i;
		}
	}
}

void	move_player_lateral(t_cub_info *cub, t_player_info *player, int i)
{
	int	tmp[2];

	tmp[0] = player->xpos + MOV_SPEED * player->xcamera * i;
	tmp[1] = player->ypos + MOV_SPEED * player->ycamera * i;
	if (cub->map[tmp[1]][tmp[0]] != '1' && cub->map[tmp[1]][tmp[0]] != 'D')
	{
		if (!ft_checkdiagmove(cub, player, tmp))
		{
			player->xpos += MOV_SPEED * player->xcamera * i;
			player->ypos += MOV_SPEED * player->ycamera * i;
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
