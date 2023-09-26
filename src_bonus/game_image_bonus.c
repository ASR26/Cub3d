/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:10:28 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 13:27:36 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	makeimage_walldoornorth(t_window_info *w, t_all_info *all, int i, int j)
{
	int		dooridx;

	if ((all->info->map[ft_fl(w->dist[i].posy)][ft_fl(w->dist[i].posx)] == '1'\
	&& all->info->map[ft_fl(w->dist[i].posy) + 1][ft_fl(w->dist[i].posx)] == 'd'\
	&& all->info->map[ft_fl(w->dist[i].posy) + 2][ft_fl(w->dist[i].posx)] == '1'\
	) || (\
	all->info->map[ft_fl(w->dist[i].posy)][ft_fl(w->dist[i].posx)] == 'd' && \
	all->info->map[ft_fl(w->dist[i].posy) + 1][ft_fl(w->dist[i].posx)] == '1'))
	{
		dooridx = ft_finddooridx(all, i, w->dist[i].wall);
		if (all->info->doordir[dooridx] == 1)
			ft_put_texturex(all, i, j, all->draw->door);
		else
			ft_puttexturemirx(all, i, j, all->draw->door);
	}
	else
		ft_put_texturex(all, i, j, all->draw->s_wall);
}

void	makeimage_walldooreast(t_window_info *w, t_all_info *all, int i, int j)
{
	int	dooridx;

	if ((all->info->map[ft_fl(w->dist[i].posy)][ft_fl(w->dist[i].posx)] == '1'\
	&& all->info->map[ft_fl(w->dist[i].posy)][ft_fl(w->dist[i].posx + 1)] == 'd'\
	&& all->info->map[ft_fl(w->dist[i].posy)][ft_fl(w->dist[i].posx + 2)] == '1'\
	) || (\
	all->info->map[ft_fl(w->dist[i].posy)][ft_fl(w->dist[i].posx)] == 'd' && \
	all->info->map[ft_fl(w->dist[i].posy)][ft_fl(w->dist[i].posx + 1)] == '1'))
	{
		dooridx = ft_finddooridx(all, i, w->dist[i].wall);
		if (all->info->doordir[dooridx] == -1)
			ft_puttexturemiry(all, i, j, all->draw->door);
		else
			ft_put_texturey(all, i, j, all->draw->door);
	}
	else
		ft_puttexturemiry(all, i, j, all->draw->e_wall);
}

void	makeimage_walls(t_window_info *window, t_all_info *all, int i, int j)
{
	if (window->dist[i].wall == 'N')
		ft_puttexturemirx(all, i, j, all->draw->n_wall);
	else if (window->dist[i].wall == 'S')
		makeimage_walldoornorth(window, all, i, j);
	else if (window->dist[i].wall == 'E')
		makeimage_walldooreast(window, all, i, j);
	else if (window->dist[i].wall == 'W')
		ft_put_texturey(all, i, j, all->draw->w_wall);
	else if (window->dist[i].wall == 'D' && window->dist[i].doorc == 'y')
		ft_put_texturex(all, i, j, all->draw->door);
	else if (window->dist[i].wall == 'D' && window->dist[i].doorc == 'x')
		ft_put_texturey(all, i, j, all->draw->door);
}

void	makeimage(t_window_info	*window, t_all_info *all)
{
	int		dist;
	float	scale;
	int		i;
	int		j;

	dist = WALL_HEI;
	i = 1;
	make_image_minimap(all);
	while (i < WID - 1)
	{
		j = 0;
		scale = dist / window->dist[i].projy;
		while (j < HEI)
		{
			if (j <= HEI / 2 - scale / 2)
				ft_put_pixel_color(all, i, j, 'c');
			else if (j >= HEI / 2 + scale / 2)
				ft_put_pixel_color(all, i, j, 'f');
			else if (j >= HEI / 2 - scale / 2 && j <= HEI / 2 + scale / 2)
				makeimage_walls(window, all, i, j);
			j++;
		}
		i++;
	}
	ft_maketreasureimage(all);
}
