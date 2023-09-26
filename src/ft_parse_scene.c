/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:28:28 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 14:30:04 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_read_scene(char *scenefile, t_cub_info *info)
{
	int		fd;
	char	*line;

	fd = open(scenefile, O_RDONLY);
	if (fd < 0)
		ft_errexit(strerror(errno));
	line = get_next_line(fd);
	while (line)
	{
		info->scene = ft_arrapp(info->scene, line);
		if (!info->scene)
			ft_errexit("Malloc error.");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!info->scene || !info->scene[0])
		ft_errfreeexit("The map is empty or it cannot be read.", info);
	return ;
}

int	ft_wfc(t_cub_info *info)
{
	int	count;

	count = 0;
	if (info->n_wall)
		count++;
	if (info->s_wall)
		count++;
	if (info->w_wall)
		count++;
	if (info->e_wall)
		count++;
	if (info->floor_col[0] >= 0 && info->floor_col[1] >= 0
		&& info->floor_col[2] >= 0)
		count++;
	if (info->ceil_col[0] >= 0 && info->ceil_col[1] >= 0
		&& info->ceil_col[2] >= 0)
		count++;
	return (count);
}

void	ft_assignvalue(char *line, int *len, int *var, t_cub_info *info)
{
	int	val;

	ft_skipspace(line, len);
	if (ft_whiledigit(&line[*len]) > 0 && ft_whiledigit(&line[*len]) < 4)
	{
		val = ft_atoi(&line[*len]);
		*len += ft_whiledigit(&line[*len]);
		if (val >= 0 && val <= 255)
			*var = val;
		else
			ft_errfreeexit("Invalid value given as color parameters.", \
			info);
	}
	else
		ft_errfreeexit("Unrecognizable parameters given as color.", info);
	ft_skipspace(line, len);
}

void	ft_search_typeid(char *line, t_cub_info *info)
{	
	int	len;

	len = -1;
	if (ft_strlen(line) >= 2 && line[0] == 'N' && line[1] == 'O')
		info->n_wall = ft_getstr(line, 2, &len);
	else if (ft_strlen(line) >= 2 && line[0] == 'S' && line[1] == 'O')
		info->s_wall = ft_getstr(line, 2, &len);
	else if (ft_strlen(line) >= 2 && line[0] == 'W' && line[1] == 'E')
		info->w_wall = ft_getstr(line, 2, &len);
	else if (ft_strlen(line) >= 2 && line[0] == 'E' && line[1] == 'A')
		info->e_wall = ft_getstr(line, 2, &len);
	else if (ft_strlen(line) >= 1 && line[0] == 'F')
		ft_getcolor(line + 1, info, 'F');
	else if (ft_strlen(line) >= 1 && line[0] == 'C')
		ft_getcolor(line + 1, info, 'C');
	else
		ft_errfreeexit("Unrecognized line in scene description file.", info);
	if (len != -1)
		ft_checkend(line, len, info);
	return ;
}

int	ft_parse_scene(char *scenefile, t_cub_info *info)
{
	ft_checkext(scenefile);
	ft_read_scene(scenefile, info);
	ft_get_elements(info);
	ft_check_closedmap(info);
	ft_check_oneplayer(info);
	return (0);
}
