/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:34:21 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/25 12:34:15 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
