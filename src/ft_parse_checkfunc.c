/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_checkfunc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:32:27 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 14:34:00 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_check_char(char c, t_cub_info *info)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'W' && c != 'E'
		&& c != ' ')
		ft_errfreeexit("Invalid character in map.", info);
}

void	ft_checkmapline(t_cub_info *info, int i)
{
	int		j;

	j = 0;
	while (info->scene[i][j])
	{
		if (info->scene[i][j] == '\t')
		{
			ft_delandinsertspace(&(info->scene[i]), j, 4 - j % 4);
		}
		ft_check_char(info->scene[i][j], info);
		j++;
	}
	info->map = ft_arrapp(info->map, info->scene[i]);
	if (!info->map)
		ft_errfreeexit("Malloc error.", info);
}

void	ft_check_closedmap(t_cub_info *info)
{
	int		i;
	int		j;
	char	**mapdup;

	i = 0;
	mapdup = ft_arrdup(info->map);
	while (mapdup[i])
	{
		j = 0;
		while (mapdup[i][j])
		{
			if (mapdup[i][j] == '0' || mapdup[i][j] == 'N' || mapdup[i][j] == \
				'S' || mapdup[i][j] == 'W' || mapdup[i][j] == 'E')
				ft_fillx(mapdup, i, j, info);
			j++;
		}
		i++;
	}
	ft_freearr(mapdup);
}
