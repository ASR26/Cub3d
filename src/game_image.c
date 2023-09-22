/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:53:37 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 16:12:33 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	makeimage_walls(t_window_info *window, t_all_info *all, int i, int j)
{
	if (window->dist[i].wall == 'N')
		ft_puttexturemirx(all, i, j, all->draw->n_wall);
	else if (window->dist[i].wall == 'S')
		ft_put_texturex(all, i, j, all->draw->s_wall);
	else if (window->dist[i].wall == 'E')
		ft_puttexturemiry(all, i, j, all->draw->e_wall);
	else if (window->dist[i].wall == 'W')
		ft_put_texturey(all, i, j, all->draw->w_wall);
}

void	makeimage(t_window_info	*window, t_all_info *all)
{
	int		dist;
	float	scale;
	int		i;
	int		j;

	dist = WALL_HEI;
	i = 1;
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
}