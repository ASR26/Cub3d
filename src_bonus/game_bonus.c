/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:55:36 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/04 13:32:58 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

// void    rot_player(t_player_info *player, int i);

// void    move_player_front(t_cub_info *cub, t_player_info *player, int i);

// void	ft_angleloop(t_cub_info *info, t_window_info *window, t_player_info *player);

// void    move_player_lateral(t_cub_info *cub, t_player_info *player, int i);

// void	ft_setdraw(t_draw *draw, t_cub_info *cub, mlx_t *mlx);

void	ft_initwindow(t_window_info	*window)
{
	window->wid = WID + M_WID;
	window->hei = HEI;
	window->mlx = mlx_init(window->wid, window->hei, "cub3d", true);
}

int ft_floor(float pos)
{
	return ((int) (pos - fmod(pos, 1.0)));
}

void	makeimage(t_window_info	*window, t_all_info *all)
{
	int dist = WALL_HEI;
	float scale;
	float scale_textur;
	float pos;
	int n;
	int k;
	float move;
	float minimapx;
	float minimapy;
	float minimapsize = M_HEI;

	int i = 1;
	int j;
	move = 10 / (minimapsize);
	//printf("move -> %f\n", move);
	while (i < M_WID + WID - 1)
	{
		if (i < M_WID)
		{
			j = 0;
			//minimapx = all->player->xpos + (-(M_HEI / 2) + i) * move * all->player->xcamera;
			//minimapy = all->player->ypos + (-M_HEI / 2 + i) * move * all->player->ycamera;
			//printf("minimapx -> %f, floor -> %i\n", minimapx, ft_floor(minimapx));
			while (j < M_HEI)
			{
				minimapx = all->player->xpos - ((M_HEI / 2) - i) * move * all->player->xcamera + ((M_HEI / 2) - j) * move * all->player->xdir;
				minimapy = all->player->ypos - (M_HEI / 2 - i) * move * all->player->ycamera + (M_HEI / 2 - j) * move * all->player->ydir;
				if ((i >= M_HEI / 2 - 4 && i <= M_HEI / 2 + 5) && (j >= M_HEI / 2 - 4 && j <= M_HEI / 2 + 5))
				{
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 0] = 255;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 1] = 0;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 2] = 0;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 3] = 255;
				}
				else if ((ft_floor(minimapx) < 0 || ft_floor(minimapx) >= all->info->wid) || (ft_floor(minimapy) < 0 || ft_floor(minimapy) >= all->info->hei))
				{
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 0] = 0;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 1] = 0;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 2] = 0;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 3] = 255;
				}
				else if (all->info->map[(int)ft_floor(minimapy)][(int)ft_floor(minimapx)] == ' ')
				{
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 0] = 0;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 1] = 0;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 2] = 0;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 3] = 255;
				}
				else if (all->info->map[(int)ft_floor(minimapy)][(int)ft_floor(minimapx)] == '1')
				{
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 0] = 255;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 1] = 255;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 2] = 255;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 3] = 255;
				}
				else if (all->info->map[(int)ft_floor(minimapy)][(int)ft_floor(minimapx)] == '0' || all->info->map[(int)ft_floor(minimapy)][(int)ft_floor(minimapx)] == 'N' || all->info->map[(int)ft_floor(minimapy)][(int)ft_floor(minimapx)] == 'E' || all->info->map[(int)ft_floor(minimapy)][(int)ft_floor(minimapx)] == 'W' || all->info->map[(int)ft_floor(minimapy)][(int)ft_floor(minimapx)] == 'S')
				{
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 0] = 28;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 1] = 91;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 2] = 5;
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 3] = 255;
				}
				j++;
			}
		}
		else
		{
			j = 0;
			scale = dist / window->dist[i - M_WID].projy;
			//printf("%c: %i, %f, %10f, %10f, %10f\n", dist, window->dist[i].wall, window->dist[i].dist,  window->dist[i].projy, window->dist[i].projx, scale);
			//printf("dist -> %f\n", window->dist[i].projy);
			//printf("scale -> %f\n", scale);
			//printf("wall -> %c\n", window->dist[i].wall);
			while (j < HEI)
			{
				if (j < HEI / 2 - scale / 2)//sky
				{
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 0] = all->info->ceil_col[0];
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 1] = all->info->ceil_col[1];
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 2] = all->info->ceil_col[2];
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 3] = 255;
				}
				else if (j > HEI / 2 + scale / 2)//floor
				{
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 0] = all->info->floor_col[0];
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 1] = all->info->floor_col[1];
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 2] = all->info->floor_col[2];
					window->g_img->pixels[window->wid * j * 4 + i * 4 + 3] = 255;
				}
					//window->g_img->pixels, 255 << 4, window->g_img->width * window->g_img->height * sizeof(int));
					//mlx_put_pixel(w->mlx, j, i, 255 << 4);
				else if (j >= HEI / 2 - scale / 2 && j <= HEI / 2 + scale / 2)
				{
					if (window->dist[i - M_WID].wall == 'N')
					{
						scale_textur = all->draw->n_wall->height/ scale ;
						pos = fmod( window->dist[i - M_WID].posx, 1.0);
						pos = (1 - pos) * all->draw->n_wall->width;
						pos = pos - fmod(pos, 1.0);
						n = (int) (scale_textur * (j - (HEI / 2 - scale / 2)));
						k = 0;
						while (k < all->draw->n_wall->bytes_per_pixel)
						{
							window->g_img->pixels[window->wid * j * 4 + i * 4 + k] = all->draw->n_wall->pixels[(int)all->draw->n_wall->width * (int)n * (int)all->draw->n_wall->bytes_per_pixel + (int)pos * (int)all->draw->n_wall->bytes_per_pixel + (int)k];
							k++;
						}
					}
					else if (window->dist[i- M_WID].wall == 'S')
					{
						scale_textur = all->draw->s_wall->height/ scale ;
						pos = fmod(window->dist[i- M_WID].posx, 1.0);
						pos = pos * all->draw->s_wall->width;
						pos = pos - fmod(pos, 1.0);
						n = (int) (scale_textur * (j - (HEI / 2 - scale / 2)));
						k = 0;
						while (k < all->draw->s_wall->bytes_per_pixel)
						{
							window->g_img->pixels[window->wid * j * 4 + i * 4 + k] = all->draw->s_wall->pixels[(int)all->draw->s_wall->width * (int)n * (int)all->draw->s_wall->bytes_per_pixel + (int)pos * (int)all->draw->s_wall->bytes_per_pixel + (int)k];
							k++;
						}
					}
					else if (window->dist[i - M_WID].wall == 'E')
					{
						scale_textur = all->draw->e_wall->height/ scale ;
						pos = fmod(window->dist[i - M_WID].posy, 1.0);
						pos = (1 - pos) * all->draw->e_wall->width;
						pos = pos - fmod(pos, 1.0);
						n = (int) (scale_textur * (j - (HEI / 2 - scale / 2)));
						k = 0;
						while (k < all->draw->e_wall->bytes_per_pixel)
						{
							window->g_img->pixels[window->wid * j * 4 + i * 4 + k] = all->draw->e_wall->pixels[(int)all->draw->e_wall->width * (int)n * (int)all->draw->e_wall->bytes_per_pixel + (int)pos * (int)all->draw->e_wall->bytes_per_pixel + (int)k];
							k++;
						}
					}
					else if (window->dist[i - M_WID].wall == 'W')
					{
						scale_textur = all->draw->w_wall->height/ scale ;
						pos = fmod(window->dist[i - M_WID].posy, 1.0);
						pos = pos * all->draw->w_wall->width;
						pos = pos - fmod(pos, 1.0);
						n = (int) (scale_textur * (j - (HEI / 2 - scale / 2)));
						k = 0;
						while (k < all->draw->w_wall->bytes_per_pixel)
						{
							window->g_img->pixels[window->wid * j * 4 + i * 4 + k] = all->draw->w_wall->pixels[(int)all->draw->w_wall->width * (int)n * (int)all->draw->w_wall->bytes_per_pixel + (int)pos * (int)all->draw->w_wall->bytes_per_pixel + (int)k];
							
							k++;
						}
					}
					else if (window->dist[i- M_WID].wall == 'D' && window->dist[i- M_WID].doorc == 'y')
					{
						scale_textur = all->draw->door->height/ scale ;
						pos = fmod(window->dist[i- M_WID].posx, 1.0);
						pos = pos * all->draw->door->width;
						pos = pos - fmod(pos, 1.0);
						n = (int) (scale_textur * (j - (HEI / 2 - scale / 2)));
						k = 0;
						while (k < all->draw->door->bytes_per_pixel)
						{
							window->g_img->pixels[window->wid * j * 4 + i * 4 + k] = all->draw->door->pixels[(int)all->draw->door->width * (int)n * (int)all->draw->door->bytes_per_pixel + (int)pos * (int)all->draw->door->bytes_per_pixel + (int)k];
							k++;
						}
					}
					else if (window->dist[i- M_WID].wall == 'D' && window->dist[i- M_WID].doorc == 'x')
					{
						scale_textur = all->draw->door->height/ scale ;
						pos = fmod(window->dist[i - M_WID].posy, 1.0);
						pos = pos * all->draw->door->width;
						pos = pos - fmod(pos, 1.0);
						n = (int) (scale_textur * (j - (HEI / 2 - scale / 2)));
						k = 0;
						while (k < all->draw->door->bytes_per_pixel)
						{
							window->g_img->pixels[window->wid * j * 4 + i * 4 + k] = all->draw->door->pixels[(int)all->draw->door->width * (int)n * (int)all->draw->door->bytes_per_pixel + (int)pos * (int)all->draw->door->bytes_per_pixel + (int)k];
							
							k++;
						}
					}
				}
				j++;
			}
		}
		i++;
	}
}

/* if (window->dist[i].wall == 'N')//dark green
				{
					

					
					window->g_img->pixels[WID * j * 4 + i * 4 + 0] = 0;
					window->g_img->pixels[WID * j * 4 + i * 4 + 1] = 94;
					window->g_img->pixels[WID * j * 4 + i * 4 + 2] = 76;
					window->g_img->pixels[WID * j * 4 + i * 4 + 3] = 255;
				}
				else if (window->dist[i].wall == 'S')//dark blue
				{
					window->g_img->pixels[WID * j * 4 + i * 4 + 0] = 0;
					window->g_img->pixels[WID * j * 4 + i * 4 + 1] = 58;
					window->g_img->pixels[WID * j * 4 + i * 4 + 2] = 76;
					window->g_img->pixels[WID * j * 4 + i * 4 + 3] = 255;
				}
				else if (window->dist[i].wall == 'E')//green
				{
					window->g_img->pixels[WID * j * 4 + i * 4 + 0] = 113;
					window->g_img->pixels[WID * j * 4 + i * 4 + 1] = 200;
					window->g_img->pixels[WID * j * 4 + i * 4 + 2] = 152;
					window->g_img->pixels[WID * j * 4 + i * 4 + 3] = 255;
				}
				else if (window->dist[i].wall == 'W')//pink
				{
					window->g_img->pixels[WID * j * 4 + i * 4 + 0] = 232;
					window->g_img->pixels[WID * j * 4 + i * 4 + 1] = 145;
					window->g_img->pixels[WID * j * 4 + i * 4 + 2] = 170;
					window->g_img->pixels[WID * j * 4 + i * 4 + 3] = 255;
				} */

/* void	ft_mlx_keyfunc(mlx_key_data_t keydata, void *param)
{	
	t_all_info *all;

	all = param;
	if (keydata.key == MLX_KEY_W && keydata.action == 2)
	{
		move_player_front(all->info, all->player, 1);
		ft_angleloop(all->info, all->window, all->player);
		makeimage(all->window);
		mlx_image_to_window(all->window->mlx, all->window->g_img, 0, 0);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == 1)
	{
		move_player_front(all->info, all->player, -1);
		ft_angleloop(all->info, all->window, all->player);
		makeimage(all->window);
		mlx_image_to_window(all->window->mlx, all->window->g_img, 0, 0);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == 1)
	{
		move_player_lateral(all->info, all->player, -1);
		ft_angleloop(all->info, all->window, all->player);
		makeimage(all->window);
		mlx_image_to_window(all->window->mlx, all->window->g_img, 0, 0);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == 1)
	{
		move_player_lateral(all->info, all->player, 1);
		ft_angleloop(all->info, all->window, all->player);
		makeimage(all->window);
		mlx_image_to_window(all->window->mlx, all->window->g_img, 0, 0);
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == 1)
	{
		rot_player(all->player, -1);
		ft_angleloop(all->info, all->window, all->player);
		makeimage(all->window);
		mlx_image_to_window(all->window->mlx, all->window->g_img, 0, 0);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == 1)
	{
		rot_player(all->player, 1);
		ft_angleloop(all->info, all->window, all->player);
		makeimage(all->window);
		mlx_image_to_window(all->window->mlx, all->window->g_img, 0, 0);
	}
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(all->window->mlx);
} */

void	ft_mlx_keyfunc(mlx_key_data_t keydata, void *param)
{	
	t_all_info *all;

	all = param;
	if (keydata.key == MLX_KEY_W)
	{
		move_player_front(all->info, all->player, 1);
		ft_angleloop(all->info, all->window, all->player);
		makeimage(all->window, all);
		mlx_image_to_window(all->window->mlx, all->window->g_img, 0, 0);
	}
	if (keydata.key == MLX_KEY_S)
	{
		move_player_front(all->info, all->player, -1);
		ft_angleloop(all->info, all->window, all->player);
		makeimage(all->window, all);
		mlx_image_to_window(all->window->mlx, all->window->g_img, 0, 0);
	}
	if (keydata.key == MLX_KEY_A)
	{
		move_player_lateral(all->info, all->player, -1);
		ft_angleloop(all->info, all->window, all->player);
		makeimage(all->window, all);
		mlx_image_to_window(all->window->mlx, all->window->g_img, 0, 0);
	}
	if (keydata.key == MLX_KEY_D)
	{
		move_player_lateral(all->info, all->player, 1);
		ft_angleloop(all->info, all->window, all->player);
		makeimage(all->window, all);
		mlx_image_to_window(all->window->mlx, all->window->g_img, 0, 0);
	}
	if (keydata.key == MLX_KEY_RIGHT)
	{
		rot_player(all->player, -1);
		ft_angleloop(all->info, all->window, all->player);
		makeimage(all->window, all);
		mlx_image_to_window(all->window->mlx, all->window->g_img, 0, 0);
	}
	if (keydata.key == MLX_KEY_LEFT)
	{
		rot_player(all->player, 1);
		ft_angleloop(all->info, all->window, all->player);
		makeimage(all->window, all);
		mlx_image_to_window(all->window->mlx, all->window->g_img, 0, 0);
	}
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(all->window->mlx);
}

void ft_hook(void *arg)
{
	t_all_info *all;

	all = arg;
	mlx_key_hook(all->window->mlx, &ft_mlx_keyfunc, all);
}

void	ft_game(t_cub_info *info, t_player_info *player)
{
	//t_player_info	player;
	t_window_info	window;
	t_all_info		all;
	t_draw			draw;

	(void) info;
	ft_initwindow(&window);
	all.window = &window;
	all.info = info;
	all.player = player;
	all.draw = &draw;
	//all.player = &player;
	ft_setdraw(&draw, info, window.mlx);
	window.g_img = mlx_new_image(window.mlx, window.wid, window.hei);
	//printf("PLAYER: xpos -> %f, ypos -> %f, angle -> %f\n", player->xpos, player->ypos, player->pov);
	//printf("PLAYER: xpos -> %f, ypos -> %f, angle -> %f\n", player->xpos, player->ypos, player->pov);
	ft_angleloop(info, &window, player);
	makeimage(&window, &all);
	mlx_image_to_window(window.mlx, window.g_img, 0, 0);
	mlx_loop_hook(window.mlx, &ft_hook, &all);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
}