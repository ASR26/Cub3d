/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enable_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:49:06 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 16:12:05 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	w->menustr[3] = mlx_put_string(w->mlx, "   TAB: Enable/disable menu", 5, \
	start);
}

void	ft_disable_menu(t_all_info *all)
{
	int	idx;

	idx = 0;
	while (idx < 4)
	{
		all->window->menustr[idx]->enabled = false;
		idx++;
	}
}

void	ft_enable_menu(t_all_info *all)
{
	int	idx;

	idx = 0;
	while (idx < 4)
	{
		all->window->menustr[idx]->enabled = true;
		idx++;
	}
}

void	ft_enable_images(t_all_info *all)
{
	all->window->g_img->enabled = true;
}

void	ft_put_images(t_all_info *all)
{
	mlx_image_to_window(all->window->mlx, all->window->g_img, 0, 0);
	ft_put_menu(all->window);
	all->window->menu = 1;
}
