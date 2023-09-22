/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:13:11 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 13:15:10 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	ft_rotate_drag(double x, t_all_info *all)
{
	float	anglex;
	float	anglelast;

	anglex = M_PI / 4 - ft_calculate_deltaang(x);
	anglelast = M_PI / 4 - ft_calculate_deltaang(all->window->lastclickx);
	rot_player_mouse(all->player, 1, (anglelast - anglex));
	ft_angleloop(all);
	all->window->lastclickx = x;
	makeimage(all->window, all);
	ft_enable_images(all);
}

void	ft_mlx_cursorfunc(double x, double y, void *param)
{
	t_all_info	*all;

	all = param;
	if (x > all->window->wid || x < 0 || y > all->window->hei || y < 0
		|| all->window->action == 0)
	{
		all->window->lastclickx = -1;
		return ;
	}
	else
	{
		if (all->window->lastclickx == -1)
		{
			all->window->lastclickx = x;
			return ;
		}
		else
			ft_rotate_drag(x, all);
	}
}

void	ft_rotate_click(t_all_info *all)
{
	int32_t	y;

	mlx_get_mouse_pos(all->window->mlx, &(all->window->lastclickx), &y);
	if (all->window->lastclickx < WID / 2)
	{
		rot_player(all->player, 1);
		ft_angleloop(all);
		makeimage(all->window, all);
		ft_enable_images(all);
	}
	else
	{
		rot_player(all->player, -1);
		ft_angleloop(all);
		makeimage(all->window, all);
		ft_enable_images(all);
	}
}

void	ft_mlx_mousefunc(mouse_key_t b, action_t a, modifier_key_t m, void *p)
{
	t_all_info	*all;

	all = p;
	(void)m;
	all->window->button = b;
	all->window->action = a;
	if (b == 0)
	{
		if (a == 1)
			ft_rotate_click(all);
	}
	else if (b == 1 && a == 1)
	{
		if (mlx_is_mouse_down(all->window->mlx, b))
		{
			mlx_cursor_hook(all->window->mlx, &ft_mlx_cursorfunc, all);
		}
	}
}
