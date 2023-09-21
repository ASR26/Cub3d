/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:45:49 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/20 09:31:35 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

double	ft_abs(double a)
{
	if (a >= 0)
		return (a);
	else
		return (-a);
}

double	ft_setang(double ang)
{
	if (ang < 0)
		return (ang + 2 * M_PI);
	else if (ang < 2 * M_PI)
		return (ft_abs(ang));
	else
		return (ang - 2 * M_PI);
}

double	ft_getangx(double ang)
{
	if (ang >= 0 && ang < M_PI / 2)
	{
		return (ang);
	}
	else if (ang >= M_PI / 2 && ang < M_PI)
	{
		return (M_PI - ang);
	}
	else if (ang >= M_PI && ang < 3 * M_PI / 2)
	{
		return (ang - M_PI);
	}
	else if (ang >= 3 * M_PI / 2 && ang < 2 * M_PI)
	{
		return (2 * M_PI - ang);
	}
	else
		return (-10);
}

double	ft_getangy(double ang)
{
	if (ang >= 0 && ang < M_PI / 2)
	{
		return (M_PI / 2 - ang);
	}
	else if (ang >= M_PI / 2 && ang < M_PI)
	{
		return (ang - M_PI / 2);
	}
	else if (ang >= M_PI && ang < 3 * M_PI / 2)
	{
		return (3 * M_PI / 2 - ang);
	}
	else if (ang >= 3 * M_PI / 2 && ang < 2 * M_PI)
	{
		return (ang - 3 * M_PI / 2);
	}
	else
		return (-10);
}

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

void	ft_xcross_util(t_all_info *all, t_dist *dist, t_impact *impact)
{
	dist->xcross = (int)(all->player->xpos - fmod(all->player->xpos, 1.0));
	impact->posx = all->player->xpos;
	impact->posy = all->player->ypos;
	impact->posx += dist->distx * dist->raydirx;
	impact->posy += dist->distx * dist->raydiry;
	dist->xcross += dist->dirx;
	impact->dist = dist->distx;
}

void	ft_loopxcrossings(t_all_info *all, t_dist *dist, t_impact *impact)
{
	ft_xcross_util(all, dist, impact);
	while ((impact->posx > 0 && impact->posx < all->info->wid)
		&& (impact->posy > 0 && impact->posy < all->info->hei))
	{
		if (all->info->map[(int)(impact->posy - fmod(impact->posy, 1.0))] \
		[dist->xcross] == '1')
		{
			if (dist->dirx == -1)
				impact->wall = 'E';
			else if (dist->dirx == 1)
				impact->wall = 'W';
			break ;
		}
		else if (all->info->map[(int)(impact->posy - fmod(impact->posy, 1.0))] \
		[dist->xcross] == 'D')
		{
			impact->wall = 'D';
			impact->doorc = 'x';
			break ;
		}
		impact->posx += dist->deltax * dist->raydirx;
		impact->posy += dist->deltax * dist->raydiry;
		impact->dist += dist->deltax;
		dist->xcross += dist->dirx;
	}
}

void	ft_ycross_util(t_all_info *all, t_dist *dist, t_impact *impact)
{
	dist->ycross = (int)(all->player->ypos - fmod(all->player->ypos, 1.0));
	impact->posx = all->player->xpos;
	impact->posy = all->player->ypos;
	impact->posx += dist->disty * dist->raydirx;
	impact->posy += dist->disty * dist->raydiry;
	dist->ycross += dist->diry;
	impact->dist = dist->disty;
}

void	ft_loopycrossings(t_all_info *all, t_dist *dist, t_impact *impact)
{
	ft_ycross_util(all, dist, impact);
	while ((impact->posx > 0 && impact->posx < all->info->wid)
		&& (dist->ycross >= 0 && dist->ycross < all->info->hei))
	{
		if (all->info->map[dist->ycross] \
		[(int)(impact->posx - fmod(impact->posx, 1.0))] == '1')
		{
			if (dist->diry == -1)
				impact->wall = 'S';
			else if (dist->diry == 1)
				impact->wall = 'N';
			break ;
		}
		else if (all->info->map[dist->ycross] \
		[(int)(impact->posx - fmod(impact->posx, 1.0))] == 'D')
		{
			impact->wall = 'D';
			impact->doorc = 'y';
			break ;
		}
		impact->posx += dist->deltay * dist->raydirx;
		impact->posy += dist->deltay * dist->raydiry;
		impact->dist += dist->deltay;
		dist->ycross += dist->diry;
	}
}

void	ft_copy_impact(t_impact *copy, t_impact src)
{
	copy->dist = src.dist;
	copy->wall = src.wall;
	copy->posx = src.posx;
	copy->posy = src.posy;
	copy->doorc = src.doorc;
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

// void	ft_one_step_right(t_all_info *all, t_dist *dist, t_impact_tc *impact)
// {
// 	(void)all;
// 	(void)dist;
// 	//if (fmod(all->player->xpos, 1.0) >= 0.5)
// 		ft_init_impact_tc(impact);
// 	/* else
// 	{
// 		impact->tc = 1;
// 		impact->tcside = 'x';
// 		impact->dist = \
// 		ft_abs(0.5 - fmod(all->player->xpos, 1.0)) / cos(dist->angx);
// 		impact->posx = impact->posx + dist->raydirx * impact->dist;
// 		impact->posy = impact->posy + dist->raydiry * impact->dist;
// 		impact->locy = (int)(impact->posy - fmod(impact->posy, 1.0));
// 		impact->projy = \
// 		y_projection(M_PI / 2 - dist->ang, impact->dist);
// 	} */
// }

// void	ft_one_step_left(t_all_info *all, t_dist *dist, t_impact_tc *impact)
// {
// 	(void)all;
// 	(void)dist;
// 	//if (fmod(all->player->xpos, 1.0) < 0.5)
// 		ft_init_impact_tc(impact);
// 	/* else
// 	{
// 		impact->tc = 1;
// 		impact->tcside = 'x';
// 		impact->dist = ft_abs(fmod(all->player->xpos, 1.0)) / cos(dist->angx);
// 		impact->posx = impact->posx + dist->raydirx * impact->dist;
// 		impact->posy = impact->posy + dist->raydiry * impact->dist;
// 		impact->locy = (int)(impact->posy - fmod(impact->posy, 1.0));
// 		impact->projy = \
// 		y_projection(M_PI / 2 - dist->ang, impact->dist);
// 	} */
// }

void	ft_xcross_util_tc(t_all_info *all, t_dist *dist, t_impact_tc *impact)
{
	impact->locx = (int)(all->player->xpos - fmod(all->player->xpos, 1.0));
	impact->posx = all->player->xpos;
	impact->posy = all->player->ypos;
	if (all->info->map[(int)(impact->posy - \
	fmod(impact->posy, 1.0))][impact->locx] == 'c')
	{
		ft_init_impact_tc(impact);
		return ;
	}
	else
	{
		impact->dist = dist->distx;
		impact->posx += dist->distx * dist->raydirx;
		impact->posy += dist->distx * dist->raydiry;
		impact->locx += dist->dirx;
	}
}

void	ft_set_impact_tcx(t_dist *dist, t_impact_tc *impact)
{
	impact->tc = 1;
	impact->tcside = 'x';
	// if (dist->dirx == 1)
	// 	impact->otherdist = \
	// 	ft_abs((0.5 - fmod(impact->posx, 1.0)) / cos(dist->angx));
	// if (dist->dirx == -1)
	// 	impact->otherdist = \
	// 	ft_abs((fmod(impact->posx, 1.0)) / cos(dist->angx));
	// //printf("x: dist->%f, otherdist->%f\n", impact->dist, impact->otherdist);
	// impact->dist += impact->otherdist;
	// impact->posx += dist->raydirx * impact->otherdist;
	// impact->posy += dist->raydiry * impact->otherdist;
	impact->locy = (int)(impact->posy - fmod(impact->posy, 1.0));
	impact->projy = y_projection(M_PI / 2 - dist->ang, impact->dist);
}

void	ft_loopxcrossings_tc(t_all_info *all, t_dist *dist, t_impact_tc *impact)
{
	ft_xcross_util_tc(all, dist, impact);
	if (impact->tc == 1)
		return ;
	while ((impact->posx > 0 && impact->posx < all->info->wid)
		&& (impact->posy > 0 && impact->posy < all->info->hei))
	{
		if (all->info->map[(int)(impact->posy - fmod(impact->posy, 1.0))] \
		[impact->locx] == 'c')
		{
			ft_set_impact_tcx(dist, impact);
			break ;
		}
		impact->posx += dist->deltax * dist->raydirx;
		impact->posy += dist->deltax * dist->raydiry;
		impact->dist += dist->deltax;
		impact->locx += dist->dirx;
	}
}

// void	ft_one_step_up(t_all_info *all, t_dist *dist, t_impact_tc *impact)
// {
// 	(void)all;
// 	(void)dist;
// 	//if (fmod(all->player->ypos, 1.0) >= 0.5)
// 		ft_init_impact_tc(impact);
// 	/* else
// 	{
// 		impact->tc = 1;
// 		impact->tcside = 'y';
// 		impact->dist = \
// 		ft_abs((0.5 - fmod(all->player->ypos, 1.0)) / sin(dist->angx));
// 		impact->posx = impact->posx + dist->raydirx * impact->dist;
// 		impact->posy = impact->posy + dist->raydiry * impact->dist;
// 		impact->locx = (int)(impact->posx - fmod(impact->posx, 1.0));
// 		impact->projy = \
// 		y_projection(M_PI / 2 - dist->ang, impact->dist);
// 	} */
// }

// void	ft_one_step_down(t_all_info *all, t_dist *dist, t_impact_tc *impact)
// {
// 	(void)all;
// 	(void)dist;
// 	//if (fmod(all->player->ypos, 1.0) < 0.5)
// 		ft_init_impact_tc(impact);
// 	/* else
// 	{
// 		impact->tc = 1;
// 		impact->tcside = 'y';
// 		impact->dist = ft_abs((fmod(all->player->ypos, 1.0)) / sin(dist->angx));
// 		impact->posx = impact->posx + dist->raydirx * impact->dist;
// 		impact->posy = impact->posy + dist->raydiry * impact->dist;
// 		impact->locx = (int)(impact->posx - fmod(impact->posx, 1.0));
// 		impact->projy = \
// 		y_projection(M_PI / 2 - dist->ang, impact->dist);
// 	} */
// }

void	ft_ycross_util_tc(t_all_info *all, t_dist *dist, t_impact_tc *impact)
{
	impact->locy = (int)(all->player->ypos - fmod(all->player->ypos, 1.0));
	impact->posx = all->player->xpos;
	impact->posy = all->player->ypos;
	if (all->info->map[impact->locy][(int)(impact->posx - \
	fmod(impact->posx, 1.0))] == 'c')
	{
		ft_init_impact_tc(impact);
		return ;
	}
	else
	{
		impact->dist = dist->disty;
		impact->posx += dist->disty * dist->raydirx;
		impact->posy += dist->disty * dist->raydiry;
		impact->locy += dist->diry;
	}
}

void	ft_set_impact_tcy(t_dist *dist, t_impact_tc *impact)
{
	impact->tc = 1;
	impact->tcside = 'y';
// 	if (dist->diry == 1)
// 		impact->otherdist = \
// 		ft_abs((0.5 - fmod(impact->posy, 1.0)) / sin(dist->angx));
// 	if (dist->diry == -1)
// 		impact->otherdist = \
// 		ft_abs((fmod(impact->posy, 1.0)) / sin(dist->angx));
// //	printf("y: dist->%f, otherdist->%f\n", impact->dist, impact->otherdist);
// 	impact->dist += impact->otherdist;
// 	impact->posx += dist->raydirx * impact->otherdist;
// 	impact->posy += dist->raydiry * impact->otherdist;
	impact->locx = (int)(impact->posx - fmod(impact->posx, 1.0));
	impact->projy = y_projection(M_PI / 2 - dist->ang, impact->dist);
}

void	ft_loopycrossings_tc(t_all_info *all, t_dist *dist, t_impact_tc *impact)
{
	ft_ycross_util_tc(all, dist, impact);
	if (impact->tc == 1)
		return ;
	while ((impact->posx > 0 && impact->posx < all->info->wid)
		&& (impact->locy >= 0 && impact->locy < all->info->hei))
	{
		if (all->info->map[impact->locy] \
		[(int)(impact->posx - fmod(impact->posx, 1.0))] == 'c')
		{
			ft_set_impact_tcy(dist, impact);
			break ;
		}
		impact->posx += dist->deltay * dist->raydirx;
		impact->posy += dist->deltay * dist->raydiry;
		impact->dist += dist->deltay;
		impact->locy += dist->diry;
	}
}

void	ft_copy_impact_tc(t_impact_tc *cpy, t_impact_tc src)
{
	cpy->tc = src.tc;
	cpy->tcside = src.tcside;
	cpy->posx = src.posx;
	cpy->posy = src.posy;
	cpy->locx = src.locx;
	cpy->locy = src.locy;
	cpy->dist = src.dist;
	cpy->projy = src.projy;
}

void	ft_impact_treasure(t_all_info *all, t_dist *dist, t_impact *impact)
{
	t_impact_tc	impactx;
	t_impact_tc	impacty;

	ft_init_impact_tc(&(impact->tc));
	ft_init_impact_tc(&impactx);
	ft_init_impact_tc(&impacty);
	if (dist->distx >= 0)
		ft_loopxcrossings_tc(all, dist, &impactx);
	if (dist->disty >= 0)
		ft_loopycrossings_tc(all, dist, &impacty);
	if (impactx.tc == 0 && impacty.tc == 0)
		return ;
	if (impactx.tc == 0 || (impactx.tc == 1 && impactx.dist > impacty.dist))
		ft_copy_impact_tc(&(impact->tc), impacty);
	if (impacty.tc == 0 || (impacty.tc == 1 && impacty.dist > impactx.dist))
		ft_copy_impact_tc(&(impact->tc), impactx);
	//printf("dist->%f\n", impact->tc.dist);
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
