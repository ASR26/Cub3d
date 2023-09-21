/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:55:36 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/21 11:17:35 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	ft_initwindow(t_window_info	*window)
{
	window->wid = WID;
	window->hei = HEI;
	window->lastclickx = -1;
	window->leftclick = 0;
	window->action = 0;
	window->button = -1;
	window->frame = 0;
	window->menu = 0;
	window->attack = 0;
	window->attack = 0;
	window->mlx = mlx_init(window->wid, window->hei, "cub3d", true);
}

/* int	ft_fl(float pos)
{
	return ((int)(pos - fmod(pos, 1.0)));
} */

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

int	ft_finddooridx(t_all_info *all, int i, char dir)
{
	int	k;

	k = 0;
	while (k < 5)
	{
		if (dir == 'S' && \
		((ft_fl(all->window->dist[i].posy) == all->info->doory[k] && \
		ft_fl(all->window->dist[i].posx) == all->info->doorx[k]) || \
		(ft_fl(all->window->dist[i].posy) + 1 == all->info->doory[k] \
		&& ft_fl(all->window->dist[i].posx) == all->info->doorx[k])))
			return (k);
		else if (dir == 'E' && \
		((ft_fl(all->window->dist[i].posy) == all->info->doory[k] && \
		ft_fl(all->window->dist[i].posx) == all->info->doorx[k]) || \
		(ft_fl(all->window->dist[i].posx) + 1 == all->info->doorx[k] \
		&& ft_fl(all->window->dist[i].posy) == all->info->doory[k])))
			return (k);
		k++;
	}
	return (k);
}

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
			if (i == j || i == M_WID - j)
				ft_put_pixel_color_mm(all, i, j, (0 << 16) + (0 << 8) + (255));
			j++;
		}
		i++;
	}
}

void	ft_freelistend(t_tc_list *list)
{
	t_tc_list	*tmp;

	while (list)
	{
		tmp = list->prev;
		free(list);
		list = tmp;
	}
}

void	ft_freelistbegin(t_tc_list *list)
{
	t_tc_list	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

void	ft_maketreasureimage(t_all_info *all)
{
	int i;
	int j;
	int k;
	int tc;
	float	pix_w;
	float	pix_h;
	float	pix_wall;
	float	dist;
	float ang;
	float posw;
	float posh;
	int locx;
	int locy;

	ft_bzero(all->window->g_img_tc->pixels, WID * HEI * 4);
	i = 0;
	tc = -1;
	while (i < WID)
	{
		if (all->window->dist[i].tc.tc == 1 && tc == -1)
			tc = i;
		i++;
	}
	if (tc > -1)
	{
		locx = all->window->dist[tc].tc.locx;
		locy = all->window->dist[tc].tc.locy;
		float slope = (all->player->ypos - (locy + 0.5))/(all->player->xpos - (locx + 0.5));
		ang = atan(-slope);
		if (locx + 0.5 >= all->player->xpos)
		{
			if (ang < 0)
				ang = ang + 2 * M_PI;
		}
		else
		{
			ang = ang + M_PI;
		}
		float angdiff= ang - all->player->pov;
		float hypo = (float)(WID / 2) / cos(angdiff);
		float side = hypo * sin(angdiff);
		tc = (int)((WID / 2) - side);
		/* if (tc > WID || tc < 0)
			return; */
		
		dist = sqrt((all->player->ypos - (locy + 0.5))*(all->player->ypos - (locy + 0.5)) + (all->player->xpos - (locx + 0.5))*(all->player->xpos - (locx + 0.5)));
		if (tc < WID / 2)
			ang = M_PI/4 - ft_calculate_deltaang(tc);
		else
			ang = -M_PI/4 + ft_calculate_deltaang(tc);
		ang = M_PI / 2 - ang;
		dist = y_projection(ang, dist);
		pix_w = T_WID / dist;
		pix_h = T_HEI / dist;
		pix_wall = WALL_HEI / dist;
		i = 0;
		while (i < pix_w && i + tc - pix_w / 2 < WID)
		{
			if (i + tc - pix_w / 2 >= 0 && i + tc - pix_w / 2 < WID && all->window->dist[(int)(i + tc - pix_w / 2)].projy > dist)
			{
				j = 0;
				posw = all->draw->treasurec->width / pix_w * i;
				while (j < pix_h && j + (HEI / 2 - pix_wall/ 2) + pix_wall - pix_h < HEI)
				{
					posh = all->draw->treasurec->height / pix_h * j;
					k = 0;
					while (k < all->draw->treasurec->bytes_per_pixel)
					{
						all->window->g_img_tc->pixels[WID * (int)(j + (HEI / 2 - pix_wall/ 2) + pix_wall - pix_h) * 4 + (int)(i + tc - pix_w / 2) * 4 + k] = all->draw->treasurec->pixels[all->draw->treasurec->width * (int)posh * all->draw->treasurec->bytes_per_pixel +  (int)posw * all->draw->treasurec->bytes_per_pixel + k];
						k++;
					}
					j++;
				}
			}
			i++;
		}
	}
}

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

	scale = WALL_HEI / all->window->dist[i].projy;
	scale_textur = texture->height / scale ;
	pos = fmod(all->window->dist[i].posx, 1.0);
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

	scale = WALL_HEI / all->window->dist[i].projy;
	scale_textur = texture->height / scale ;
	pos = fmod(all->window->dist[i].posy, 1.0);
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

	scale = WALL_HEI / all->window->dist[i].projy;
	scale_textur = texture->height / scale;
	pos = fmod(all->window->dist[i].posx, 1.0);
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

	scale = WALL_HEI / all->window->dist[i].projy;
	scale_textur = texture->height / scale;
	pos = fmod(all->window->dist[i].posy, 1.0);
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

void	makeimage_walldorrnorth(t_window_info *w, t_all_info *all, int i, int j)
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
		makeimage_walldorrnorth(window, all, i, j);
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

void	ft_makeweaponimage(mlx_image_t *img, mlx_texture_t *tx, int wid, int hei)
{
	int	i;
	int	j;
	int	k;
	int	imgh;
	int	imgw;

	i = 0;
	while (i < wid)
	{
		imgw = (int)ft_fl(((float)tx->width / (float)wid) * i);
		j = 0;
		while (j < hei)
		{
			imgh = (int)ft_fl((((float)tx->height / (float) hei)) * j);
			k = 0;
			while (k < tx->bytes_per_pixel)
			{
				img->pixels[wid * j * 4 + i * 4 + k] = tx->pixels[(tx->width * \
				imgh * tx->bytes_per_pixel) + imgw * tx->bytes_per_pixel + k];
				k++;
			}
			j++;
		}
		i++;
	}
}

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
	w->menustr[5] = mlx_put_string(w->mlx, "   E: Open doors", 5, start);
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

void	ft_finddoor(t_all_info *all, t_impact dimpact, int idx)
{
	if (dimpact.doorc == 'x')
	{
		all->info->map[ft_fl(dimpact.posy)] \
		[ft_fl(dimpact.posx) + ft_dir(all->player, 'x')] = 'd';
		all->info->doordir[idx] = ft_dir(all->player, 'x');
		all->info->doorx[idx] = ft_fl(dimpact.posx) + ft_dir(all->player, 'x');
		all->info->doory[idx] = ft_fl(dimpact.posy);
	}
	else if (dimpact.doorc == 'y')
	{
		all->info->map[ft_fl(dimpact.posy) + ft_dir(all->player, 'y')] \
		[ft_fl(dimpact.posx)] = 'd';
		all->info->doordir[idx] = ft_dir(all->player, 'y');
		all->info->doorx[idx] = ft_fl(dimpact.posx);
		all->info->doory[idx] = ft_fl(dimpact.posy) + ft_dir(all->player, 'y');
	}
}

void	ft_opendoor(t_all_info *all)
{
	t_impact	dimpact;
	int			idx;

	ft_calculatedist(all, 0, &dimpact);
	if (dimpact.wall == 'D' && dimpact.dist < 1)
	{
		idx = 0;
		while (all->info->doordir[idx] && idx < 5)
			idx++;
		if (all->info->map[ft_fl(dimpact.posy)][ft_fl(dimpact.posx)] == 'D')
		{
			all->info->map[ft_fl(dimpact.posy)][ft_fl(dimpact.posx)] = 'd';
			all->info->doorx[idx] = ft_fl(dimpact.posx);
			all->info->doory[idx] = ft_fl(dimpact.posy);
			if (dimpact.doorc == 'x')
				all->info->doordir[idx] = ft_dir(all->player, 'x');
			else if (dimpact.doorc == 'y')
				all->info->doordir[idx] = ft_dir(all->player, 'y');
		}
		else
			ft_finddoor(all, dimpact, idx);
	}
}

void	ft_move_and_image(t_all_info *all, int move)
{
	if (move == 0)
		move_player_front(all->info, all->player, 1);
	else if (move == 1)
		move_player_front(all->info, all->player, -1);
	else if (move == 2)
		move_player_lateral(all->info, all->player, -1);
	else if (move == 3)
		move_player_lateral(all->info, all->player, 1);
	else if (move == 4)
		rot_player(all->player, -1);
	else if (move == 5)
		rot_player(all->player, 1);
	else if (move == 6)
		ft_opendoor(all);
	ft_angleloop(all);
	makeimage(all->window, all);
}

void	ft_tabkey(t_all_info *all)
{
	if (all->window->menustr[0]->enabled)
		ft_disable_menu(all);
	else
		ft_enable_menu(all);
}

void	ft_fkey(t_all_info *all)
{
	if (all->window->attack == 0)
	{
		all->window->attack = 1;
		all->window->attackbegin = all->window->frame;
		ft_enable_images(all);
	}
}

void	ft_mlx_keyfunc(mlx_key_data_t keydata, void *param)
{	
	t_all_info	*all;

	all = param;
	if (keydata.key == MLX_KEY_W)
		ft_move_and_image(all, 0);
	if (keydata.key == MLX_KEY_S)
		ft_move_and_image(all, 1);
	if (keydata.key == MLX_KEY_A)
		ft_move_and_image(all, 2);
	if (keydata.key == MLX_KEY_D)
		ft_move_and_image(all, 3);
	if (keydata.key == MLX_KEY_RIGHT)
		ft_move_and_image(all, 4);
	if (keydata.key == MLX_KEY_LEFT)
		ft_move_and_image(all, 5);
	if (keydata.key == MLX_KEY_E && keydata.action == 1)
		ft_move_and_image(all, 6);
	if (keydata.key == MLX_KEY_TAB && keydata.action == 1)
		ft_tabkey(all);
	if (keydata.key == MLX_KEY_F && keydata.action == 1)
		ft_fkey(all);
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(all->window->mlx);
}

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

void	ft_hook(void *arg)
{
	t_all_info	*all;

	all = arg;
	mlx_key_hook(all->window->mlx, &ft_mlx_keyfunc, all);
	if (all->window->frame % 5 == 0)
		mlx_mouse_hook(all->window->mlx, &ft_mlx_mousefunc, all);
	if (all->window->attack)
	{
		ft_enable_images(all);
	}
	all->window->frame++;
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

void	ft_delete_textures(t_all_info *all)
{
	int	i;

	mlx_delete_texture(all->draw->n_wall);
	mlx_delete_texture(all->draw->s_wall);
	mlx_delete_texture(all->draw->e_wall);
	mlx_delete_texture(all->draw->w_wall);
	if (all->draw->door)
		mlx_delete_texture(all->draw->door);
	mlx_delete_texture(all->draw->treasurec);
	mlx_delete_texture(all->draw->treasureo);
	mlx_delete_texture(all->draw->weapon);
	i = 0;
	while (i < 10)
	{
		mlx_delete_texture(all->draw->weapon_mv[i]);
		i++;
	}
}

void	ft_game(t_cub_info *info, t_player_info *player)
{
	t_window_info	window;
	t_all_info		all;
	t_draw			draw;

	(void) info;
	ft_setdraw(&draw, info);
	ft_initwindow(&window);
	all.window = &window;
	all.info = info;
	all.player = player;
	all.draw = &draw;
	window.g_img = mlx_new_image(window.mlx, WID, HEI);
	window.g_img_mm = mlx_new_image(window.mlx, M_WID, M_HEI);
	window.g_img_w = mlx_new_image(window.mlx, W_WID, W_HEI);
	window.g_img_tc = mlx_new_image(window.mlx, WID, HEI);
	ft_makeweaponimage(all.window->g_img_w, all.draw->weapon, W_WID, W_HEI);
	ft_makeweaponmvimages(&all);
	ft_angleloop(&all);
	makeimage(&window, &all);
	ft_put_images(&all);
	mlx_loop_hook(window.mlx, &ft_hook, &all);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
	ft_delete_textures(&all);
}
