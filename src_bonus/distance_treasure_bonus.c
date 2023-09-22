/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_treasure_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:19:29 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/21 13:22:16 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

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
}
