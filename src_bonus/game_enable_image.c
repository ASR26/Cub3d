/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enable_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:20:52 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 13:21:45 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	ft_put_menu(t_window_info *w)
{
	int	linesize;
	int	start;

	start = HEI - 250;
	linesize = 30;
	w->menustr[0] = mlx_put_string(w->mlx, "CONTROLS", 150, start);
	start += linesize;
	w->menustr[1] = mlx_put_string(w->mlx, "   W/A/S/D: Move", 5, start);
	start += linesize;
	w->menustr[2] = mlx_put_string(w->mlx, "   LEFT/RIGHT ARROWS: Rotate", \
	5, start);
	start += linesize;
	w->menustr[3] = mlx_put_string(w->mlx, "   LEFT CLICK: Rotate", 5, start);
	start += linesize;
	w->menustr[4] = mlx_put_string(w->mlx, "   RIGHT CLICK DRAG: Rotate", 5, \
	start);
	start += linesize;
	w->menustr[5] = mlx_put_string(w->mlx, "   E: Open", 5, start);
	start += linesize;
	w->menustr[6] = mlx_put_string(w->mlx, "   F: Attack", 5, start);
	start += linesize;
	w->menustr[7] = mlx_put_string(w->mlx, "   TAB: Enable/disable menu", 5, \
	start);
}

void	ft_disable_menu(t_all_info *all)
{
	int	idx;

	idx = 0;
	while (idx < 8)
	{
		all->window->menustr[idx]->enabled = false;
		idx++;
	}
}

void	ft_enable_menu(t_all_info *all)
{
	int	idx;

	idx = 0;
	while (idx < 8)
	{
		all->window->menustr[idx]->enabled = true;
		idx++;
	}
}

void	ft_enable_images(t_all_info *all)
{
	int	idx;

	all->window->g_img->enabled = true;
	all->window->g_img_mm->enabled = true;
	all->window->g_img_tc->enabled = true;
	if (all->window->attack)
	{
		idx = (all->window->frame - all->window->attackbegin);
		if (idx < 10)
		{
			all->window->g_img_w->enabled = false;
			if (idx > 0)
				all->window->g_img_wmv[idx - 1]->enabled = false;
			all->window->g_img_wmv[idx]->enabled = true;
		}
		else
		{
			all->window->g_img_wmv[9]->enabled = false;
			all->window->g_img_w->enabled = true;
			all->window->attack = 0;
		}
	}
	else
		all->window->g_img_w->enabled = true;
}

void	ft_put_images(t_all_info *all)
{
	int	idx;

	mlx_image_to_window(all->window->mlx, all->window->g_img, 0, 0);
	mlx_image_to_window(all->window->mlx, all->window->g_img_mm, 0, 0);
	mlx_image_to_window(all->window->mlx, all->window->g_img_tc, 0, 0);
	idx = 0;
	mlx_image_to_window(all->window->mlx, all->window->g_img_w, 400, HEI - 350);
	while (idx < 10)
	{
		all->window->g_img_wmv[idx]->enabled = false;
		mlx_image_to_window(all->window->mlx, all->window->g_img_wmv[idx], \
		400, HEI - 350);
		idx++;
	}
	ft_put_menu(all->window);
	all->window->menu = 1;
}
