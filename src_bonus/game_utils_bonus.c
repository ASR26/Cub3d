/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:22:35 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 13:38:17 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	ft_fl(float pos)
{
	if (fmod(pos, 1.0) < 0)
		return ((int)(pos - (1 - fmod(pos, 1.0))));
	else
		return ((int)(pos - fmod(pos, 1.0)));
}

int	ft_dir(t_player_info *player, char c)
{
	if (c == 'x')
	{
		if (player->pov < M_PI / 2 || player->pov > 3 * M_PI / 2)
			return (1);
		else if (player->pov > M_PI / 2 && player->pov < 3 * M_PI / 2)
			return (-1);
		else
			return (0);
	}
	else if (c == 'y')
	{
		if (player->pov > 0 && player->pov < M_PI)
			return (-1);
		else if (player->pov > M_PI && player->pov < 2 * M_PI)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

void	ft_makeweaponimage(mlx_image_t *img, mlx_texture_t *tx, int w, int h)
{
	int	i;
	int	j;
	int	k;
	int	imgh;
	int	imgw;

	i = 0;
	while (i < w)
	{
		imgw = (int)ft_fl(((float)tx->width / (float)w) * i);
		j = 0;
		while (j < h)
		{
			imgh = (int)ft_fl((((float)tx->height / (float) h)) * j);
			k = 0;
			while (k < tx->bytes_per_pixel)
			{
				img->pixels[w * j * 4 + i * 4 + k] = tx->pixels[(tx->width * \
				imgh * tx->bytes_per_pixel) + imgw * tx->bytes_per_pixel + k];
				k++;
			}
			j++;
		}
		i++;
	}
}

void	ft_makeweaponmvimages(t_all_info *all)
{
	int	idx;

	idx = 0;
	while (idx < 10)
	{
		all->window->g_img_wmv[idx] = \
		mlx_new_image(all->window->mlx, W_WID, W_HEI);
		ft_makeweaponimage(all->window->g_img_wmv[idx], \
		all->draw->weapon_mv[idx], W_WID, W_HEI);
		idx++;
	}
}
