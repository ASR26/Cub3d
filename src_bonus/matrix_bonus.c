/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:22:19 by asolano-          #+#    #+#             */
/*   Updated: 2023/09/22 15:11:42 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"
#include <math.h>

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
