/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   andres.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:49:26 by ysmeding          #+#    #+#             */
/*   Updated: 2023/08/25 08:14:15 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANDRES_H
# define ANDRES_H
# define ROT_SPEED M_PI/36
# define MOV_SPEED 0.1f
typedef struct s_draw
{
	mlx_texture_t   *n_wall;
	mlx_texture_t	*s_wall;
	mlx_texture_t	*w_wall;
	mlx_texture_t	*e_wall;
}			        t_draw;

typedef struct s_ray
{
	float	dist;
	char	c;
	float	touch_x;
	double	touch_y;
}			t_ray;

float   y_projection (float angle, float dist);
float   x_projection (float angle, float dist);
void	rotate_z(double *x, double *y, double ang);
#endif