/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:36:36 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/21 13:40:22 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

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
