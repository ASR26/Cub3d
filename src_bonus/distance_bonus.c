/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:45:49 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/21 13:23:42 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	ft_copy_impact(t_impact *copy, t_impact src)
{
	copy->dist = src.dist;
	copy->wall = src.wall;
	copy->posx = src.posx;
	copy->posy = src.posy;
	copy->doorc = src.doorc;
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
	if (dist.distx >= 0)
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
	ft_impact_treasure(all, &dist, impact);
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

void	ft_angleloop(t_all_info	*all)
{
	double		delta_ang;
	double		ang;
	int			i;

	i = 1;
	ang = M_PI / 4;
	while (i < WID / 2)
	{
		delta_ang = ft_calculate_deltaang(i);
		ft_calculatedist(all, ang - delta_ang, &(all->window->dist[i]));
		ft_calculatedist(all, -ang + delta_ang,
			&(all->window->dist[WID - 1 - i]));
		i++;
	}
}
