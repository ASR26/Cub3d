/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freefunc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:51:40 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/01 09:53:50 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

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
