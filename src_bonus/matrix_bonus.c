/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:22:19 by asolano-          #+#    #+#             */
/*   Updated: 2023/09/01 09:54:12 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"
#include <math.h>
/*
t_point	mul_mat(float matrix[3][3], t_point point)
{
	int		i;
	int		j;
	t_point	result;

	result = point;
	i = 0;
	while (i < 3)
	{
		result.axis[i] = 0;
		result.color = point.color;
		j = 0;
		while (j < 3)
		{
			result.axis[i] += matrix[i][j] * point.axis[j];
			j++;
		}
		i++;
	}
	return (result);
}

void	rotate_x(t_point *points, t_point *proyection, float ang, int len)
{
	int		i;
	float	rad;
	float	proyect_matrix[3][3];

	rad = ang * M_PI / 180;
	matrix_init(proyect_matrix);
	proyect_matrix[0][0] = 1;
	proyect_matrix[1][1] = cos(rad);
	proyect_matrix[1][2] = -sin(rad);
	proyect_matrix[2][1] = sin(rad);
	proyect_matrix[2][2] = cos(rad);
	i = 0;
	while (i < len)
	{
		proyection[i] = mul_mat(proyect_matrix, points[i]);
		i++;
	}
}

void	rotate_y(t_point *points, t_point *proyection, float ang, int len)
{
	int		i;
	float	rad;
	float	proyect_matrix[3][3];

	rad = ang * M_PI / 180;
	matrix_init(proyect_matrix);
	proyect_matrix[0][0] = cos(rad);
	proyect_matrix[1][1] = 1;
	proyect_matrix[0][2] = sin(rad);
	proyect_matrix[2][0] = -sin(rad);
	proyect_matrix[2][2] = cos(rad);
	i = 0;
	while (i < len)
	{
		proyection[i] = mul_mat(proyect_matrix, points[i]);
		i++;
	}
}
*/
void	rotate_z(double *x, double *y, double ang)
{
	double	dupx;
	double	dupy;

	dupx = *x;
	dupy = *y;
	ang = -ang;
	*x = dupx * cos(ang) - dupy * sin(ang);
	*y = dupx * sin(ang) + dupy * cos(ang);
}
/*
void	orto_proyection(t_point *points, t_point *proyection, int len)
{
	int		i;
	float	proyect_matrix[3][3];

	matrix_init(proyect_matrix);
	proyect_matrix[0][0] = 1;
	proyect_matrix[1][1] = 1;
	i = 0;
	while (i < len)
	{
		proyection[i] = mul_mat(proyect_matrix, points[i]);
		i++;
	}
}*/