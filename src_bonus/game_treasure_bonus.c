/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_treasure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:03:20 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 13:04:22 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	ft_settreasure2(t_treasure *treasure)
{
	if (treasure->tc < WID / 2)
		treasure->ang = M_PI / 4 - ft_calculate_deltaang(treasure->tc);
	else
		treasure->ang = -M_PI / 4 + ft_calculate_deltaang(treasure->tc);
	treasure->ang = M_PI / 2 - treasure->ang;
	treasure->dist = y_projection(treasure->ang, treasure->dist);
	treasure->pix_w = T_WID / treasure->dist;
	treasure->pix_h = T_HEI / treasure->dist;
	treasure->pix_wall = WALL_HEI / treasure->dist;
}

void	ft_settreasure(t_all_info *all, t_treasure *treasure)
{
	treasure->locx = all->window->dist[treasure->tc].tc.locx;
	treasure->locy = all->window->dist[treasure->tc].tc.locy;
	treasure->slope = (all->player->ypos - (treasure->locy + 0.5)) / \
	(all->player->xpos - (treasure->locx + 0.5));
	treasure->ang = atan(-treasure->slope);
	if (treasure->locx + 0.5 >= all->player->xpos)
	{
		if (treasure->ang < 0)
			treasure->ang = treasure->ang + 2 * M_PI;
	}
	else
		treasure->ang = treasure->ang + M_PI;
	treasure->angdiff = treasure->ang - all->player->pov;
	treasure->hypo = (float)(WID / 2) / cos(treasure->angdiff);
	treasure->side = treasure->hypo * sin(treasure->angdiff);
	treasure->tc = (int)((WID / 2) - treasure->side);
	treasure->dist = sqrt((all->player->ypos - (treasure->locy + 0.5)) * \
	(all->player->ypos - (treasure->locy + 0.5)) + (all->player->xpos - \
	(treasure->locx + 0.5)) * (all->player->xpos - (treasure->locx + 0.5)));
	ft_settreasure2(treasure);
}

void	ft_drawtreasure(t_all_info *all, t_treasure *tr, int i)
{
	int				j;
	int				k;
	mlx_texture_t	*tx;

	j = 0;
	if (all->window->t_oc == 0)
		tx = all->draw->treasurec;
	else
		tx = all->draw->treasureo;
	tr->posw = tx->width / tr->pix_w * i;
	while (j < tr->pix_h && j + (HEI / 2 - tr->pix_wall / 2) \
	+ tr->pix_wall - tr->pix_h < HEI)
	{
		tr->posh = tx->height / tr->pix_h * j;
		k = -1;
		while (++k < tx->bytes_per_pixel)
		{
			all->window->g_img_tc->pixels[WID * ((int)(j + (HEI / 2 - \
			tr->pix_wall / 2) + tr->pix_wall - tr->pix_h)) * 4 + (int)(i + \
			tr->tc - tr->pix_w / 2) * 4 + k] = tx->pixels[tx->width * \
			(int)tr->posh * tx->bytes_per_pixel + (int)tr->posw * \
			tx->bytes_per_pixel + k];
		}
		j++;
	}
}

void	ft_treasurefound(t_all_info *all, t_treasure *treasure)
{
	int			i;

	ft_settreasure(all, treasure);
	i = 0;
	while (i < treasure->pix_w && i + treasure->tc - treasure->pix_w / 2 < WID)
	{
		if (i + treasure->tc - treasure->pix_w / 2 >= 0 && i + treasure->tc - \
		treasure->pix_w / 2 < WID && all->window->dist[(int)(i + treasure->tc - \
		treasure->pix_w / 2)].projy > treasure->dist)
		{
			ft_drawtreasure(all, treasure, i);
		}
		i++;
	}
}

void	ft_maketreasureimage(t_all_info *all)
{
	int			i;
	t_treasure	treasure;

	ft_bzero(all->window->g_img_tc->pixels, WID * HEI * 4);
	i = 0;
	treasure.tc = -1;
	while (i < WID)
	{
		if (all->window->dist[i].tc.tc == 1 && treasure.tc == -1)
			treasure.tc = i;
		i++;
	}
	if (treasure.tc > -1)
		ft_treasurefound(all, &treasure);
}
