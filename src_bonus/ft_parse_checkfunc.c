/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_checkfunc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:41:40 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/21 13:43:21 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	ft_check_char(char c, t_cub_info *info)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'W' && c != 'E'
		&& c != ' ' && c != 'D' && c != 'c')
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
				'S' || mapdup[i][j] == 'W' || mapdup[i][j] == 'E'
				|| mapdup[i][j] == 'D' || mapdup[i][j] == 'c')
				ft_fillx(mapdup, i, j, info);
			j++;
		}
		i++;
	}
	ft_freearr(mapdup);
}

void	ft_checkdoorwalls(int i, int j, t_cub_info *info)
{
	if ((info->map[i - 1][j] == '1' && info->map[i + 1][j] == '1')
		|| (info->map[i][j - 1] == '1' && info->map[i][j + 1] == '1'))
		return ;
	else
		ft_errfreeexit("Doors must be located between two walls.", info);
}

void	ft_check_door(t_cub_info *info)
{
	int	i;
	int	j;
	int	doorcount;

	doorcount = 0;
	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'D')
			{
				ft_checkdoorwalls(i, j, info);
				doorcount++;
			}
			j++;
		}
		i++;
	}
	if (doorcount && info->door[0] == 0)
	{
		ft_errfreeexit("The map has at least one door but there is \
no door texture.", info);
	}
}
