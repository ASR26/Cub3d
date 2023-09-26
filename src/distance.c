/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:53:37 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/25 09:45:24 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_copy_impact(t_impact *copy, t_impact src)
{
	copy->dist = src.dist;
	copy->wall = src.wall;
	copy->posx = src.posx;
	copy->posy = src.posy;
}

void	ft_calculatedist(t_all_info *all, double ang, t_impact *impact)
{
	t_dist		dist;
	t_impact	impactx;
	t_impact	impacty;

	ft_init_impact(impact);
	ft_init_impact(&impactx);
	ft_init_impact(&impacty);
	ft_init_dist(&dist, all->player, ang);
	if (dist.distx >= 0 && dist.distx)
		ft_loopxcrossings(all, &dist, &impactx);
	if (dist.disty >= 0)
		ft_loopycrossings(all, &dist, &impacty);
	if (impactx.wall == 0 || (impactx.dist > impacty.dist && impacty.dist >= 0))
	{
		ft_copy_impact(impact, impacty);
	}
	else if (impacty.wall == 0
		|| (impacty.dist >= impactx.dist && impactx.dist >= 0))
	{
		ft_copy_impact(impact, impactx);
	}
	impact->projx = x_projection(M_PI / 2 - ang, impact->dist);
	impact->projy = y_projection(M_PI / 2 - ang, impact->dist);
}

double	ft_calculate_deltaang(int i)
{
	double	side_a;
	double	side_b;
	double	side_c;
	double	angle_a;
	double	angle_b;

	side_c = (WID / 2) / (sin(M_PI / 4));
	angle_a = M_PI / 4;
	side_b = (double) i + 0.5;
	side_a = sqrt(side_b * side_b + side_c * side_c
			- 2 * side_b * side_c * cos(angle_a));
	angle_b = asin((sin(angle_a) / side_a) * side_b);
	return (angle_b);
}
