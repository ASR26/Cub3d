/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yolanthe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:49:01 by ysmeding          #+#    #+#             */
/*   Updated: 2023/08/18 11:58:52 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YOLANTHE_H
# define YOLANTHE_H

# include "cub3d.h"
# include <math.h>

typedef struct s_window_info
{
	mlx_t	*mlx;
	int		wid;
	int		hei;
}			t_window_info;

typedef struct s_all_info
{
	//t_cub_info		*info;
	t_window_info	*window;
	//t_player_info	*player;
}			t_all_info;



/* --------------------------------- BULLSHIT --------------------------------- */

typedef struct s_draw
{
	mlx_image_t	*n_wall;
	mlx_image_t	*e_wall;
	mlx_image_t	*s_wall;
	mlx_image_t	*w_wall;
}				t_draw;

#endif