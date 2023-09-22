/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freefunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:51:40 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 15:54:22 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_freearr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_freearr2(char **arr, char **newarr)
{
	if (arr)
		free(arr);
	ft_freearr(newarr);
}

void	ft_free_info(t_cub_info *info)
{
	if (info->scene)
		ft_freearr(info->scene);
	if (info->map)
		ft_freearr(info->map);
	if (info->n_wall)
		free(info->n_wall);
	if (info->s_wall)
		free(info->s_wall);
	if (info->w_wall)
		free(info->w_wall);
	if (info->e_wall)
		free(info->e_wall);
}

void	ft_free_draw(t_draw *draw)
{
	if (draw->n_wall)
		mlx_delete_texture(draw->n_wall);
	if (draw->s_wall)
		mlx_delete_texture(draw->s_wall);
	if (draw->e_wall)
		mlx_delete_texture(draw->e_wall);
	if (draw->w_wall)
		mlx_delete_texture(draw->w_wall);
}
