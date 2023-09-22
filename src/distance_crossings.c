/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_crossings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:57:17 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 13:58:16 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
		impact->posx += dist->deltay * dist->raydirx;
		impact->posy += dist->deltay * dist->raydiry;
		impact->dist += dist->deltay;
		dist->ycross += dist->diry;
	}
}
