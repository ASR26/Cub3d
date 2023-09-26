/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:10:04 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 15:10:38 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_fl(float pos)
{
	if (fmod(pos, 1.0) < 0)
		return ((int)(pos - (1 - fmod(pos, 1.0))));
	else
		return ((int)(pos - fmod(pos, 1.0)));
}

int	ft_dir(t_player_info *player, char c)
{
	if (c == 'x')
	{
		if (player->pov < M_PI / 2 || player->pov > 3 * M_PI / 2)
			return (1);
		else if (player->pov > M_PI / 2 && player->pov < 3 * M_PI / 2)
			return (-1);
		else
			return (0);
	}
	else if (c == 'y')
	{
		if (player->pov > 0 && player->pov < M_PI)
			return (-1);
		else if (player->pov > M_PI && player->pov < 2 * M_PI)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
