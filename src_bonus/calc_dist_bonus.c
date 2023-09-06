/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:28:04 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/06 13:28:06 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

float   x_projection (float angle, float dist)
{
    float   projection;

    projection = -cos(angle) * dist;
    return (projection);
}

float   y_projection (float angle, float dist)
{
    float   projection;

    projection = sin(angle) * dist;
    return (projection);
}