/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:55:36 by ysmeding          #+#    #+#             */
/*   Updated: 2023/08/24 11:08:49 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_angleloop(t_cub_info *info, t_window_info *window, t_player_info *player);

void	ft_initwindow(t_window_info	*window)
{
	window->wid = 1800;
	window->hei = 1080;
	window->mlx = mlx_init(window->wid, window->hei, "cub3d", true);
}

void ft_hook(void *arg)
{
	(void)arg;
}

void	makeimage(t_window_info	*window)
{
	int dist = 1080;
	float scale;

	int i = 0;
	int j;
	while (i < 1800)
	{
		j = 0;
		scale = dist / window->dist[i].projy;
		printf("%c: %i, %f, %10f, %10f, %10f\n", dist, window->dist[i].wall, window->dist[i].dist,  window->dist[i].projy, window->dist[i].projx, scale);
		//printf("dist -> %f\n", window->dist[i].projy);
		//printf("scale -> %f\n", scale);
		//printf("wall -> %c\n", window->dist[i].wall);
		while (j < 1080)
		{
			if (j < 540 - scale / 2)//sky
			{
				window->g_img->pixels[1800 * j * 4 + i * 4 + 0] = 59;
				window->g_img->pixels[1800 * j * 4 + i * 4 + 1] = 171;
				window->g_img->pixels[1800 * j * 4 + i * 4 + 2] = 255;
				window->g_img->pixels[1800 * j * 4 + i * 4 + 3] = 255;
			}
			else if (j > 540 + scale / 2)
			{
				window->g_img->pixels[1800 * j * 4 + i * 4 + 0] = 113;
				window->g_img->pixels[1800 * j * 4 + i * 4 + 1] = 66;
				window->g_img->pixels[1800 * j * 4 + i * 4 + 2] = 52;
				window->g_img->pixels[1800 * j * 4 + i * 4 + 3] = 255;
			}
				//window->g_img->pixels, 255 << 4, window->g_img->width * window->g_img->height * sizeof(int));
				//mlx_put_pixel(w->mlx, j, i, 255 << 4);
			else if (j >= 540 - scale / 2 || j <= 540 + scale / 2)
			{
				if (window->dist[i].wall == 'N')//dark green
				{
					window->g_img->pixels[1800 * j * 4 + i * 4 + 0] = 0;
					window->g_img->pixels[1800 * j * 4 + i * 4 + 1] = 94;
					window->g_img->pixels[1800 * j * 4 + i * 4 + 2] = 76;
					window->g_img->pixels[1800 * j * 4 + i * 4 + 3] = 255;
				}
				else if (window->dist[i].wall == 'S')//dark blue
				{
					window->g_img->pixels[1800 * j * 4 + i * 4 + 0] = 0;
					window->g_img->pixels[1800 * j * 4 + i * 4 + 1] = 58;
					window->g_img->pixels[1800 * j * 4 + i * 4 + 2] = 76;
					window->g_img->pixels[1800 * j * 4 + i * 4 + 3] = 255;
				}
				else if (window->dist[i].wall == 'E')//purple(ish)
				{
					window->g_img->pixels[1800 * j * 4 + i * 4 + 0] = 129;
					window->g_img->pixels[1800 * j * 4 + i * 4 + 1] = 58;
					window->g_img->pixels[1800 * j * 4 + i * 4 + 2] = 88;
					window->g_img->pixels[1800 * j * 4 + i * 4 + 3] = 255;
				}
				else if (window->dist[i].wall == 'W')//orange
				{
					window->g_img->pixels[1800 * j * 4 + i * 4 + 0] = 255;
					window->g_img->pixels[1800 * j * 4 + i * 4 + 1] = 126;
					window->g_img->pixels[1800 * j * 4 + i * 4 + 2] = 0;
					window->g_img->pixels[1800 * j * 4 + i * 4 + 3] = 255;
				}
				
			}
				//memset(window->g_img->pixels, 255 << 8, window->g_img->width * window->g_img->height * sizeof(int));
				//mlx_put_pixel(w->mlx, j, i, 255 << 8);
			j++;
		}
		i++;
	}
}

void	ft_game(t_cub_info *info, t_player_info *player)
{
	//t_player_info	player;
	t_window_info	window;
	t_all_info		all;

	(void) info;
	ft_initwindow(&window);
	all.window = &window;
	//all.player = &player;
	window.g_img = mlx_new_image(window.mlx, 1800, 1080);
	ft_angleloop(info, &window, player);
	//memset(window.g_img->pixels, 255 << 24 | 1, window.g_img->width * window.g_img->height * sizeof(int));
	makeimage(&window);
	mlx_image_to_window(window.mlx, window.g_img, 0, 0);
	mlx_loop_hook(window.mlx, &ft_hook, &window);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
}