/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_putpixels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:08:05 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/25 09:07:25 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_put_pixel_color(t_all_info *all, int i, int j, char c)
{
	int	r;
	int	g;
	int	b;

	if (c == 'c')
	{
		r = all->info->ceil_col[0];
		g = all->info->ceil_col[1];
		b = all->info->ceil_col[2];
	}
	if (c == 'f')
	{
		r = all->info->floor_col[0];
		g = all->info->floor_col[1];
		b = all->info->floor_col[2];
	}
	all->window->g_img->pixels[WID * j * 4 + (i) * 4 + 0] = r;
	all->window->g_img->pixels[WID * j * 4 + (i) * 4 + 1] = g;
	all->window->g_img->pixels[WID * j * 4 + (i) * 4 + 2] = b;
	all->window->g_img->pixels[WID * j * 4 + (i) * 4 + 3] = 255;
}

void	ft_put_texturex(t_all_info *all, int i, int j, mlx_texture_t *texture)
{
	float	scale;
	float	pos;
	float	scale_textur;
	int		n;
	int		k;

	scale = WALL_HEI / all->window->dist.projy;
	scale_textur = texture->height / scale ;
	pos = fmod(all->window->dist.posx, 1.0);
	pos = pos * texture->width;
	pos = pos - fmod(pos, 1.0);
	n = (int)(scale_textur * (j - (HEI / 2 - scale / 2)));
	k = 0;
	while (k < texture->bytes_per_pixel)
	{
		all->window->g_img->pixels[WID * j * 4 + (i) * 4 + k] = \
		texture->pixels[texture->width * n * texture->bytes_per_pixel \
		+ (int)pos * texture->bytes_per_pixel + k];
		k++;
	}
}

void	ft_put_texturey(t_all_info *all, int i, int j, mlx_texture_t *texture)
{
	float	scale;
	float	pos;
	float	scale_textur;
	int		n;
	int		k;

	scale = WALL_HEI / all->window->dist.projy;
	scale_textur = texture->height / scale ;
	pos = fmod(all->window->dist.posy, 1.0);
	pos = pos * texture->width;
	pos = pos - fmod(pos, 1.0);
	n = (int)(scale_textur * (j - (HEI / 2 - scale / 2)));
	k = 0;
	while (k < texture->bytes_per_pixel)
	{
		all->window->g_img->pixels[WID * j * 4 + (i) * 4 + k] = \
		texture->pixels[texture->width * n * texture->bytes_per_pixel \
		+ (int)pos * texture->bytes_per_pixel + k];
		k++;
	}
}

void	ft_puttexturemirx(t_all_info *all, int i, int j, mlx_texture_t *texture)
{
	float	scale;
	float	pos;
	float	scale_textur;
	int		n;
	int		k;

	scale = WALL_HEI / all->window->dist.projy;
	scale_textur = texture->height / scale;
	pos = fmod(all->window->dist.posx, 1.0);
	pos = (1 - pos) * texture->width;
	pos = pos - fmod(pos, 1.0);
	n = (int)(scale_textur * (j - (HEI / 2 - scale / 2)));
	k = 0;
	while (k < texture->bytes_per_pixel)
	{
		all->window->g_img->pixels[WID * j * 4 + (i) * 4 + k] = \
		texture->pixels[texture->width * n * texture->bytes_per_pixel \
		+ (int)pos * texture->bytes_per_pixel + k];
		k++;
	}
}

void	ft_puttexturemiry(t_all_info *all, int i, int j, mlx_texture_t *texture)
{
	float	scale;
	float	pos;
	float	scale_textur;
	int		n;
	int		k;

	scale = WALL_HEI / all->window->dist.projy;
	scale_textur = texture->height / scale;
	pos = fmod(all->window->dist.posy, 1.0);
	pos = (1 - pos) * texture->width;
	pos = pos - fmod(pos, 1.0);
	n = (int)(scale_textur * (j - (HEI / 2 - scale / 2)));
	k = 0;
	while (k < texture->bytes_per_pixel)
	{
		all->window->g_img->pixels[WID * j * 4 + (i) * 4 + k] = \
		texture->pixels[texture->width * n * texture->bytes_per_pixel \
		+ (int)pos * texture->bytes_per_pixel + k];
		k++;
	}
}
