/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:31:18 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/19 14:58:11 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	ft_check_oneplayer(t_cub_info *info)
{
	int	found;
	int	tc;
	int	i;
	int	j;

	found = 0;
	tc = 0;
	i = -1;
	while (info->map && info->map[++i])
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S' || \
				info->map[i][j] == 'E' || info->map[i][j] == 'W')
				found++;
			if (info->map[i][j] == 'c')
				tc++;
		}
	}
	if (found != 1)
		ft_errfreeexit("There must be 1 player.", info);
	if (tc > 1)
		ft_errfreeexit("There is more than one treasure chest.", info);
}
