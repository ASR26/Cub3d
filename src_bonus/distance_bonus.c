/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:45:49 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/04 13:35:53 by ysmeding         ###   ########.fr       */
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
	dist->rayang = ft_setang(player->pov + ang);
	ft_setdistxvar(dist, player);
	ft_setdistyvar(dist, player);
	dist->raydirx = player->xdir;
	dist->raydiry = player->ydir;
	rotate_z(&(dist->raydirx), &(dist->raydiry), ang);
	if (dist->rayang > M_PI / 2 && dist->rayang < 3 * M_PI /2)
		dist->dirx = -1;
	else
		dist->dirx = 1;
	if (dist->rayang > 0 && dist->rayang < M_PI)
		dist->diry = -1;
	else
		dist->diry = 1;
}

void	ft_loopxcrossings(t_cub_info *info, t_player_info *player, t_dist *dist, t_impact *impact)
{
	dist->xcross = (int)(player->xpos - fmod(player->xpos, 1.0));
	impact->posx = player->xpos;
	impact->posy = player->ypos;
	impact->posx += dist->distx * dist->raydirx;
	impact->posy += dist->distx * dist->raydiry;
	dist->xcross += dist->dirx;
	impact->dist = dist->distx;
	// printf("xpos -> %f\n", impact->posx);
	// printf("ypos -> %f\n", impact->posy);
	// printf("wid -> %i\n", info->wid );
	// printf("hei -> %i\n", info->hei);
	while ((impact->posx > 0 && impact->posx < info->wid) && (impact->posy > 0
		&& impact->posy < info->hei))
	{
		// printf("xpos -> %f\n", impact->posx);
		// printf("ypos -> %f\n", impact->posy);
		if (info->map[(int)(impact->posy - fmod(impact->posy, 1.0))] \
		[dist->xcross] == '1')
		{
			if (dist->dirx == -1)
				impact->wall = 'E';
			else if (dist->dirx == 1)
				impact->wall = 'W';
			break ;
		}
		else if (info->map[(int)(impact->posy - fmod(impact->posy, 1.0))] \
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

void	ft_loopycrossings(t_cub_info *info, t_player_info *player, t_dist *dist, t_impact *impact)
{
	dist->ycross = (int)(player->ypos - fmod(player->ypos, 1.0));
	impact->posx = player->xpos;
	impact->posy = player->ypos;
	impact->posx += dist->disty * dist->raydirx;
	impact->posy += dist->disty * dist->raydiry;
	dist->ycross += dist->diry;
	impact->dist = dist->disty;
	// printf("angle of ray-> %f\n", dist->rayang);
	// printf("xpos -> %f\n", impact->posx);
	// printf("ypos -> %f\n", impact->posy);
	// printf("wid -> %i\n", info->wid );
	// printf("hei -> %i\n", info->hei);
	//printf("ycross -> %i\n", dist->ycross);
	while ((impact->posx > 0 && impact->posx < info->wid) && (dist->ycross >= 0
		&& dist->ycross < info->hei))
	{
		// printf("xpos -> %i\n", (int)(impact->posx - fmod(impact->posx, 1.0)));
		// printf("ycross -> %i\n", dist->ycross);
		if (info->map[dist->ycross] \
		[(int)(impact->posx - fmod(impact->posx, 1.0))] == '1')
		{
			if (dist->diry == -1)
				impact->wall = 'S';
			else if (dist->diry == 1)
				impact->wall = 'N';
			break ;
		}
		else if (info->map[dist->ycross] \
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

void 	ft_calculatedist(t_cub_info *info, t_player_info *player, double ang, t_impact *impact)
{
	t_dist		dist;
	t_impact	impactx;
	t_impact	impacty;

	ft_init_impact(impact);
	ft_init_impact(&impactx);
	ft_init_impact(&impacty);
	ft_init_dist(&dist, player, ang);
	if (dist.distx >= 0)
		ft_loopxcrossings(info, player, &dist, &impactx);
	if (dist.disty >= 0)
		ft_loopycrossings(info, player, &dist, &impacty);
	if (impactx.wall == 0 || impactx.dist > impacty.dist)
		ft_copy_impact(impact, impacty);
	else if (impacty.wall == 0 || impacty.dist >= impactx.dist)
		ft_copy_impact(impact, impactx);
	impact->projx = x_projection(M_PI / 2 - ang, impact->dist);
	impact->projy = y_projection(M_PI / 2 - ang, impact->dist);

	/* printf("\ndist -> %f\n", impact->dist);
	printf("wall -> %c\n", impact->wall);
	printf("posx -> %f\n", impact->posx);
	printf("posy -> %f\n", impact->posy);
	printf("projx -> %f\n", impact->projx);
	printf("projy -> %f\n\n", impact->projy); */
}

double	ft_calculate_deltaang(int i)
{
	double side_a;
	double side_b;
	double side_c;
	double angle_a;
	double angle_b;

	side_c = (WID / 2)/(sin(M_PI / 4));
	angle_a = M_PI / 4;
	side_b = (double) i;
	side_a = sqrt(side_b * side_b + side_c * side_c - 2 * side_b * side_c * cos(angle_a));
	angle_b = asin((sin(angle_a)/side_a) * side_b);
	//printf("angle comput: \na -> %f\nb -> %f\nc -> %f\nalpha -> %f\nbeta -> %f\n ", side_a, side_b,side_c, angle_a, angle_b);
	return(angle_b);
}

void	ft_angleloop(t_cub_info *info, t_window_info *window, t_player_info *player)
{
	double		delta_ang;
	double		ang;
	int			i;

	i = 1;
	ang = M_PI / 4;
	while (i < WID / 2)
	{
		//printf("i -> %i, other -> %i\n", i, WID-1-i);
		delta_ang = ft_calculate_deltaang(i);
		//printf("computed delta -> %f\n", delta_ang);
		ft_calculatedist(info, player, ang - delta_ang, &(window->dist[i]));
		//printf("computed left dist\n");
		ft_calculatedist(info, player, -ang + delta_ang, &(window->dist[WID - 1 - i]));
		//printf("computed right dist\n");
		i++;
	}
}

/* ------------------------- REMOVE THIS LATER!!!!! ------------------------- */

/* void    set_player_rot(t_player_info *player, char c)
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
        player->ydir = 1;
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
        player->ydir = -1;
        player->pov = 3 * M_PI / 2;
    }
} 

int main()
{
	t_player_info player;
	t_dist dist;

	player.xpos = 0.99999999999999;
	player.ypos = 0.5;
	set_player_rot(&player, 'E');
	dist.rayang = player.pov;
	ft_setdistxvar(&dist, &player);
	printf("distx -> %f\n", dist.distx);
	printf("deltax -> %f\n", dist.deltax);
} */