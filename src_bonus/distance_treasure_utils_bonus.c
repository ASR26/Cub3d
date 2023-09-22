/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_treasure_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:21:25 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/21 13:22:10 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

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

void	ft_set_impact_tcx(t_dist *dist, t_impact_tc *impact)
{
	impact->tc = 1;
	impact->tcside = 'x';
	impact->locy = (int)(impact->posy - fmod(impact->posy, 1.0));
	impact->projy = y_projection(M_PI / 2 - dist->ang, impact->dist);
}

void	ft_set_impact_tcy(t_dist *dist, t_impact_tc *impact)
{
	impact->tc = 1;
	impact->tcside = 'y';
	impact->locx = (int)(impact->posx - fmod(impact->posx, 1.0));
	impact->projy = y_projection(M_PI / 2 - dist->ang, impact->dist);
}
