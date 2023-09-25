/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:51:12 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 15:51:56 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

float	x_projection(float angle, float dist)
{
	float	projection;

	projection = -cos(angle) * dist;
	return (projection);
}

float	y_projection(float angle, float dist)
{
	float	projection;

	projection = sin(angle) * dist;
	return (projection);
}
