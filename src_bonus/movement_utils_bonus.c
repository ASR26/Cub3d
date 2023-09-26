/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:58:43 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/21 13:00:03 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

float	ft_dist(t_cub_info *cub, t_player_info *player, int idx)
{
	float	dist;
	float	diffx;
	float	diffy;

	diffx = player->xpos - (cub->doorx[idx] + 0.5f);
	diffy = player->ypos - (cub->doory[idx] + 0.5f);
	dist = sqrt(diffx * diffx + diffy * diffy);
	return (dist);
}

void	ft_close_door(t_cub_info *cub, int idx)
{
	cub->map[cub->doory[idx]][cub->doorx[idx]] = 'D';
	cub->doordir[idx] = 0;
	cub->doorx[idx] = 0;
	cub->doory[idx] = 0;
}

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
