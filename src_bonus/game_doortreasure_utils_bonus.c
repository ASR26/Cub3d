/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_doortreasure_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:18:51 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 13:37:45 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	ft_finddooridx(t_all_info *all, int i, char dir)
{
	int	k;

	k = 0;
	while (k < 5)
	{
		if (dir == 'S' && \
		((ft_fl(all->window->dist[i].posy) == all->info->doory[k] && \
		ft_fl(all->window->dist[i].posx) == all->info->doorx[k]) || \
		(ft_fl(all->window->dist[i].posy) + 1 == all->info->doory[k] \
		&& ft_fl(all->window->dist[i].posx) == all->info->doorx[k])))
			return (k);
		else if (dir == 'E' && \
		((ft_fl(all->window->dist[i].posy) == all->info->doory[k] && \
		ft_fl(all->window->dist[i].posx) == all->info->doorx[k]) || \
		(ft_fl(all->window->dist[i].posx) + 1 == all->info->doorx[k] \
		&& ft_fl(all->window->dist[i].posy) == all->info->doory[k])))
			return (k);
		k++;
	}
	return (k);
}

void	ft_finddoor(t_all_info *all, t_impact dimpact, int idx)
{
	if (dimpact.doorc == 'x')
	{
		all->info->map[ft_fl(dimpact.posy)] \
		[ft_fl(dimpact.posx) + ft_dir(all->player, 'x')] = 'd';
		all->info->doordir[idx] = ft_dir(all->player, 'x');
		all->info->doorx[idx] = ft_fl(dimpact.posx) + ft_dir(all->player, 'x');
		all->info->doory[idx] = ft_fl(dimpact.posy);
	}
	else if (dimpact.doorc == 'y')
	{
		all->info->map[ft_fl(dimpact.posy) + ft_dir(all->player, 'y')] \
		[ft_fl(dimpact.posx)] = 'd';
		all->info->doordir[idx] = ft_dir(all->player, 'y');
		all->info->doorx[idx] = ft_fl(dimpact.posx);
		all->info->doory[idx] = ft_fl(dimpact.posy) + ft_dir(all->player, 'y');
	}
}

int	ft_seetreasure(t_all_info *all)
{
	t_impact	impact;

	ft_calculatedist(all, 0, &impact);
	if (impact.tc.tc == 1)
	{
		if (impact.tc.dist < impact.dist && impact.tc.dist < 0.75)
			return (1);
	}
	return (0);
}

void	ft_opendoor(t_all_info *all)
{
	t_impact	dimpact;
	int			idx;

	ft_calculatedist(all, 0, &dimpact);
	if (dimpact.wall == 'D' && dimpact.dist < 1)
	{
		idx = 0;
		while (all->info->doordir[idx] && idx < 5)
			idx++;
		if (all->info->map[ft_fl(dimpact.posy)][ft_fl(dimpact.posx)] == 'D')
		{
			all->info->map[ft_fl(dimpact.posy)][ft_fl(dimpact.posx)] = 'd';
			all->info->doorx[idx] = ft_fl(dimpact.posx);
			all->info->doory[idx] = ft_fl(dimpact.posy);
			if (dimpact.doorc == 'x')
				all->info->doordir[idx] = ft_dir(all->player, 'x');
			else if (dimpact.doorc == 'y')
				all->info->doordir[idx] = ft_dir(all->player, 'y');
		}
		else
			ft_finddoor(all, dimpact, idx);
	}
	if (ft_seetreasure(all))
		all->window->t_oc = 1;
}
