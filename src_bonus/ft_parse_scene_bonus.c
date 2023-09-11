/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_scene_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:16:06 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/11 08:48:56 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

//void    ft_check_dup_param(t_cub_info *info);

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

int	ft_wfcd(t_cub_info *info)
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
	if (info->door)
		count++;
	return (count);
}

int	ft_whiledigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

void	ft_skipspace(char *line, int *len)
{
	while (line[*len] && line[*len] <= 32)
		(*len)++;
}

void	ft_skipcomma(char *line, int *len, t_cub_info *info)
{
	if (line[*len] == ',')
		(*len)++;
	else
		ft_errfreeexit("Unrecognizable parameters given as color.", info);
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
	else if (ft_strlen(line) >= 2 && line[0] == 'D' && line[1] == 'O')
		info->door = ft_getstr(line, 2, &len);
	else
		ft_errfreeexit("Unrecognized line in scene description file.", info);
	if (len != -1)
		ft_checkend(line, len, info);
	return ;
}

void	ft_skip_emptyline(t_cub_info *info, int i)
{
	int	stop;
	int	j;

	stop = 0;
	while (!stop && info->scene[i])
	{
		j = 0;
		ft_skipspace(info->scene[i], &j);
		if (!info->scene[i][j])
			info->scene = ft_arrremove(info->scene, i);
		else
			stop = 1;
	}
}

void	ft_check_char(char c, t_cub_info *info)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'W' && c != 'E'
		&& c != ' ' && c != 'D' && c != 'c')
		ft_errfreeexit("Invalid character in map.", info);
}

void	ft_delandinsertspace(char **str, int p, int n)
{
	char	*s;
	int		i;

	s = ft_substr(*str, 0, p);
	i = 0;
	while (i < n)
	{
		s = ft_straddfree(s, ' ');
		i++;
	}
	s = ft_strjoinfree(s, ft_substr(*str, p + 1, ft_strlen(*str + p + 1)), 3);
	free(*str);
	*str = s;
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

int	ft_strlen_no_space_end(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len > 0)
	{
		if (str[len - 1] < 32)
			len--;
		else
			break ;
	}
	return (len);
}

char	*ft_addspaces(char *str, int len, int maxlen)
{
	while (len < maxlen)
	{
		str = ft_straddfree(str, ' ');
		len++;
	}
	return (str);
}

void	ft_makemap_rectangular(t_cub_info *info)
{
	int	i;
	int	len;
	int	maxlen;

	i = 0;
	maxlen = 0;
	while (info->map[i])
	{
		len = ft_strlen_no_space_end(info->map[i]);
		if (len > maxlen)
			maxlen = len;
		i++;
	}
	i = 0;
	while (info->map[i])
	{
		len = ft_strlen(info->map[i]);
		if (len < maxlen)
			info->map[i] = ft_addspaces(info->map[i], len, maxlen);
		else if (len > maxlen)
			info->map[i] = ft_substrfree(info->map[i], 0, maxlen);
		i++;
	}
}

void	ft_get_elements(t_cub_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->scene[i] && ft_wfcd(info) < 7)
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

int	ft_step(char **map, int row, int col, t_cub_info *info)
{
	if (map[row][col] == '1' || map[row][col] == 'x')
		return (-1);
	else if (row == 0 || row == info->hei - 1 || col == 0 \
			|| col == info->wid -1)
	{
		ft_errfreeexit("The map is not closed.", info);
		return (-2);
	}
	else if (info->map[row][col] == ' ')
	{
		ft_errfreeexit("The map is not closed.", info);
		return (-2);
	}
	else
		return (0);
}

void	ft_fillx(char **map, int row, int col, t_cub_info *info)
{
	map[row][col] = 'x';
	if (row + 1 < info->hei && ft_step(map, row + 1, col, info) == 0)
		ft_fillx(map, row + 1, col, info);
	if (row - 1 >= 0 && ft_step(map, row - 1, col, info) == 0)
		ft_fillx(map, row - 1, col, info);
	if (col + 1 < info->wid && ft_step(map, row, col + 1, info) == 0)
		ft_fillx(map, row, col + 1, info);
	if (col - 1 >= 0 && ft_step(map, row, col - 1, info) == 0)
		ft_fillx(map, row, col - 1, info);
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
	int i;
	int j;
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

int	ft_parse_scene(char *scenefile, t_cub_info *info)
{
	ft_checkext(scenefile);
	ft_read_scene(scenefile, info);
	ft_get_elements(info);
	ft_check_closedmap(info);
	ft_check_oneplayer(info);
	ft_check_door(info);
	return (0);
}

/* 
	printf("n_wall -> %s\n", info->n_wall);
	printf("s_wall -> %s\n", info->s_wall);
	printf("e_wall -> %s\n", info->e_wall);
	printf("w_wall -> %s\n", info->w_wall);
	printf("floor col 0 -> %i\n", info->floor_col[0]);
	printf("floor col 1 -> %i\n", info->floor_col[1]);
	printf("floor col 2 -> %i\n", info->floor_col[2]);
	printf("ceil col 0 -> %i\n", info->ceil_col[0]);
	printf("ceil col 1 -> %i\n", info->ceil_col[1]);
	printf("ceil col 2 -> %i\n", info->ceil_col[2]); 
	int i;
	i = 0;
	while(info->map[i])
	{
		printf("%s\n", info->map[i]);
		i++;
	}
*/