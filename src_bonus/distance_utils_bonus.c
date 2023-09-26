/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:17:10 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/21 13:18:34 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

double	ft_abs(double a)
{
	if (a >= 0)
		return (a);
	else
		return (-a);
}

double	ft_setang(double ang)
{
	if (ang < 0)
		return (ang + 2 * M_PI);
	else if (ang < 2 * M_PI)
		return (ft_abs(ang));
	else
		return (ang - 2 * M_PI);
}

double	ft_getangx(double ang)
{
	if (ang >= 0 && ang < M_PI / 2)
	{
		return (ang);
	}
	else if (ang >= M_PI / 2 && ang < M_PI)
	{
		return (M_PI - ang);
	}
	else if (ang >= M_PI && ang < 3 * M_PI / 2)
	{
		return (ang - M_PI);
	}
	else if (ang >= 3 * M_PI / 2 && ang < 2 * M_PI)
	{
		return (2 * M_PI - ang);
	}
	else
		return (-10);
}

double	ft_getangy(double ang)
{
	if (ang >= 0 && ang < M_PI / 2)
	{
		return (M_PI / 2 - ang);
	}
	else if (ang >= M_PI / 2 && ang < M_PI)
	{
		return (ang - M_PI / 2);
	}
	else if (ang >= M_PI && ang < 3 * M_PI / 2)
	{
		return (3 * M_PI / 2 - ang);
	}
	else if (ang >= 3 * M_PI / 2 && ang < 2 * M_PI)
	{
		return (ang - 3 * M_PI / 2);
	}
	else
		return (-10);
}
