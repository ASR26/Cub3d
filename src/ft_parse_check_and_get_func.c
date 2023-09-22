/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_check_and_get_func.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:30:56 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 14:32:10 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_checkext(char *scenefile)
{
	int	len;

	len = ft_strlen(scenefile);
	if (len > 4 && scenefile[len - 4] == '.' && scenefile[len - 3] == 'c'
		&& scenefile[len - 2] == 'u' && scenefile[len - 1] == 'b')
		return (0);
	else
		ft_errexit("The program takes a .cub file as parameter.");
	return (1);
}

void	ft_checkend(char *line, int len, t_cub_info *info)
{
	ft_skipspace(line, &len);
	if (line[len] != 0)
		ft_errfreeexit("Unclear parameters passed to type identifier.", info);
}

void	ft_getcolor(char *line, t_cub_info *info, char c)
{
	int	i;
	int	len;
	int	*ptr[3];

	i = 0;
	len = 0;
	if (c == 'F')
	{
		ptr[0] = &(info->floor_col[0]);
		ptr[1] = &(info->floor_col[1]);
		ptr[2] = &(info->floor_col[2]);
	}
	if (c == 'C')
	{
		ptr[0] = &(info->ceil_col[0]);
		ptr[1] = &(info->ceil_col[1]);
		ptr[2] = &(info->ceil_col[2]);
	}
	ft_assignvalue(line, &len, ptr[0], info);
	ft_skipcomma(line, &len, info);
	ft_assignvalue(line, &len, ptr[1], info);
	ft_skipcomma(line, &len, info);
	ft_assignvalue(line, &len, ptr[2], info);
	ft_checkend(line, len, info);
	return ;
}

void	ft_get_map(t_cub_info *info, int i)
{
	int	j;
	int	len;

	while (info->scene[i])
	{
		j = 0;
		ft_skipspace(info->scene[i], &j);
		if (info->scene[i][j])
			ft_checkmapline(info, i);
		else
			info->map = ft_arrapp(info->map, "");
		i++;
	}
	len = ft_arrlen(info->map);
	j = len - 1;
	while (j >= 0)
	{
		if (info->map[j][0] == 0)
			info->map = ft_arrremove(info->map, j);
		else
			break ;
		j--;
	}
}

void	ft_get_elements(t_cub_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->scene[i] && ft_wfc(info) < 6)
	{
		j = 0;
		ft_skipspace(info->scene[i], &j);
		if (!info->scene[i][j])
		{
			info->scene = ft_arrremove(info->scene, i);
			i--;
		}
		else
			ft_search_typeid(&(info->scene[i][j]), info);
		i++;
	}
	ft_skip_emptyline(info, i);
	ft_check_dup_param(info);
	ft_get_map(info, i);
	if (!info->map || !info->map[0])
		ft_errfreeexit("No map encountered in scene description file.", info);
	ft_makemap_rectangular(info);
	info->wid = ft_strlen(info->map[0]);
	info->hei = ft_arrlen(info->map);
}