/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_image_minimap_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:35:34 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/25 13:26:14 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	ft_put_pixel_color_mm(t_all_info *all, int i, int j, int color)
{
	int	r;
	int	g;
	int	b;

	r = color >> 16;
	g = (color << 8) >> 16;
	b = (color << 16) >> 16;
	all->window->g_img_mm->pixels[M_WID * j * 4 + i * 4 + 0] = r;
	all->window->g_img_mm->pixels[M_WID * j * 4 + i * 4 + 1] = g;
	all->window->g_img_mm->pixels[M_WID * j * 4 + i * 4 + 2] = b;
	all->window->g_img_mm->pixels[M_WID * j * 4 + i * 4 + 3] = 255;
}

void	make_image_minimap_iter(t_all_info *all, int i, int j, t_minimapit mm)
{
	if ((i >= M_HEI / 2 - 2 && i <= M_HEI / 2 + 3) && (j >= M_HEI / 2 - 2 \
	&& j <= M_HEI / 2 + 3))
		ft_put_pixel_color_mm(all, i, j, (255 << 16) + (0 << 8) + (0));
	else if ((mm.minimapx_f < 0 || mm.minimapx_f >= all->info->wid) || \
	(mm.minimapy_f < 0 || mm.minimapy_f >= all->info->hei) || \
	(all->info->map[(int)mm.minimapy_f][(int)mm.minimapx_f] == ' '))
		ft_put_pixel_color_mm(all, i, j, (0 << 16) + (0 << 8) + (0));
	else if (all->info->map[mm.minimapy_f][mm.minimapx_f] == '1')
		ft_put_pixel_color_mm(all, i, j, (2 << 16) + (48 << 8) + (32));
	else if (all->info->map[mm.minimapy_f][mm.minimapx_f] == 'D')
		ft_put_pixel_color_mm(all, i, j, (102 << 16) + (52 << 8) + (0));
	else if (all->info->map[mm.minimapy_f][mm.minimapx_f] == '0' || \
	all->info->map[mm.minimapy_f][mm.minimapx_f] == 'N' || \
	all->info->map[mm.minimapy_f][mm.minimapx_f] == 'E' || \
	all->info->map[mm.minimapy_f][mm.minimapx_f] == 'W' || \
	all->info->map[mm.minimapy_f][mm.minimapx_f] == 'S' || \
	all->info->map[mm.minimapy_f][mm.minimapx_f] == 'd')
		ft_put_pixel_color_mm(all, i, j, (28 << 16) + (91 << 8) + (5));
	else if (all->info->map[mm.minimapy_f][mm.minimapx_f] == 'c')
		ft_put_pixel_color_mm(all, i, j, (184 << 16) + (134 << 8) + (11));
}

void	make_image_minimap(t_all_info *all)
{
	int			i;
	int			j;
	t_minimapit	mm;
	float		move;

	mm.minimapsize = M_HEI;
	move = 10 / (mm.minimapsize);
	i = 0;
	while (i < M_WID)
	{
		j = 0;
		while (j < M_HEI)
		{
			mm.minimapx_f = ft_fl(all->player->xpos \
			- ((M_HEI / 2) - i) * move * all->player->xcamera \
			+ ((M_HEI / 2) - j) * move * all->player->xdir);
			mm.minimapy_f = ft_fl(all->player->ypos \
			- (M_HEI / 2 - i) * move * all->player->ycamera \
			+ (M_HEI / 2 - j) * move * all->player->ydir);
			make_image_minimap_iter(all, i, j, mm);
			j++;
		}
		i++;
	}
}
