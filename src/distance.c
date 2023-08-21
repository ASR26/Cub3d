/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:45:49 by ysmeding          #+#    #+#             */
/*   Updated: 2023/08/18 12:04:11 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calculatedist(t_cub_info *info, t_window_info *window, t_player_info *player)
{
	int		dist_vertline[1800];
	double	delta_ang;
	double	ang;

	delta_ang = M_PI / window->wid;
	ang = -M_PI / 4;
	while (ang < M_PI / 4)
	{
		
		ang += delta_ang;
	}

}