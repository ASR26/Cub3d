/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:18:10 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/21 13:31:12 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	ft_setdistxvar(t_dist *dist, t_player_info *player)
{
	dist->angx = ft_getangx(dist->rayang);
	if (dist->rayang > M_PI / 2 && dist->rayang < 3 * M_PI / 2)
	{
		dist->distx = ft_abs(fmod(player->xpos, 1.0) / cos(dist->angx));
		dist->deltax = ft_abs(1 / cos(dist->angx));
	}
	else if (dist->rayang < M_PI / 2 || dist->rayang > 3 * M_PI / 2)
	{
		dist->distx = ft_abs((1 - fmod(player->xpos, 1.0)) / cos(dist->angx));
		dist->deltax = ft_abs(1 / cos(dist->angx));
	}
	else if (dist->rayang == M_PI / 2 || dist->rayang == 3 * M_PI / 2)
	{
		dist->distx = -1;
		dist->deltax = -1;
	}
}

void	ft_setdistyvar(t_dist *dist, t_player_info *player)
{
	dist->angy = ft_getangy(dist->rayang);
	if (dist->rayang > 0 && dist->rayang < M_PI)
	{
		dist->disty = ft_abs(fmod(player->ypos, 1.0) / cos(dist->angy));
		dist->deltay = ft_abs(1 / cos(dist->angy));
	}
	else if (dist->rayang > M_PI)
	{
		dist->disty = ft_abs((1 - fmod(player->ypos, 1.0)) / cos(dist->angy));
		dist->deltay = ft_abs(1 / cos(dist->angy));
	}
	else if (dist->rayang == 0 || dist->rayang == M_PI)
	{
		dist->disty = -1;
		dist->deltay = -1;
	}
}

void	ft_init_impact(t_impact *impact)
{
	impact->dist = -1;
	impact->wall = 0;
	impact->doorc = 0;
	impact->posx = -1;
	impact->posy = -1;
}

void	ft_init_dist(t_dist *dist, t_player_info *player, double ang)
{
	dist->ang = ang;
	dist->rayang = ft_setang(player->pov + ang);
	ft_setdistxvar(dist, player);
	ft_setdistyvar(dist, player);
	dist->raydirx = player->xdir;
	dist->raydiry = player->ydir;
	rotate_z(&(dist->raydirx), &(dist->raydiry), ang);
	if (dist->rayang > M_PI / 2 && dist->rayang < 3 * M_PI / 2)
		dist->dirx = -1;
	else
		dist->dirx = 1;
	if (dist->rayang > 0 && dist->rayang < M_PI)
		dist->diry = -1;
	else
		dist->diry = 1;
}

void	ft_init_impact_tc(t_impact_tc *impact)
{
	impact->tc = 0;
	impact->tcside = 0;
	impact->posx = -1;
	impact->posy = -1;
	impact->locx = -1;
	impact->locy = -1;
	impact->dist = -1;
	impact->projy = -1;
	impact->otherdist = -1;
}
