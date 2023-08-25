/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yolanthe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:49:01 by ysmeding          #+#    #+#             */
/*   Updated: 2023/08/25 09:35:35 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YOLANTHE_H
# define YOLANTHE_H

# include "cub3d.h"
# include <math.h>

#define WID 1800
#define HEI 1080
#define WALL_HEI 1000

typedef struct s_impact
{
	double	dist; //dist from player to first impact with wall 
	char	wall;
	double	posx; //x pos of player plus ray of distance dist (should be x pos of impact eventually)
	double	posy; //y pos of player plus ray of distance dist (should be y pos of impact eventually)
	double	projx;
	double	projy;
	double	deltadist;
}			t_impact;


typedef struct s_window_info
{
	mlx_t		*mlx;
	int			wid;
	int			hei;
	mlx_image_t	*g_img;
	t_impact	dist[WID]; //if window width changes, change this
}			t_window_info;

typedef struct s_dist
{
	double	distx; //dist to first x crossing in ray direction
	double	disty; //dist to first y crossing in ray direction
	double	deltax; //dist from one x crossing to the next
	double	deltay; //dist from one y crossing to the next
	double	angx;  //->angle of rayvector with horizon
	double	angy;  //->angle of rayvector with vertical line
	double	rayang;
	double	raydirx;
	double	raydiry;
	int		xcross;
	int		ycross;
	int		dirx;
	int		diry;
}			t_dist;



/* --------------------------------- BULLSHIT --------------------------------- */

/* typedef struct s_draw
{
	mlx_image_t	*n_wall;
	mlx_image_t	*e_wall;
	mlx_image_t	*s_wall;
	mlx_image_t	*w_wall;
}				t_draw; */

#endif