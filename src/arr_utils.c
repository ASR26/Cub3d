/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:51:56 by ysmeding          #+#    #+#             */
/*   Updated: 2023/08/15 12:54:33 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

char	*ft_strtrimnl(char *str)
{
	char	*new;

	new = ft_strtrim(str, "\n");
	return (new);
}

char	**ft_arrapp(char **arr, char *app)
{
	int		i;
	char	**newarr;

	newarr = malloc((ft_arrlen(arr) + 2) * sizeof(char *));
	if (!newarr)
		ft_freearr(arr);
	if (newarr)
	{
		i = 0;
		while (i < ft_arrlen(arr))
		{
			newarr[i] = arr[i];
			i++;
		}
		newarr[i] = ft_strtrimnl(app);
		if (!newarr[i])
			return (ft_freearr2(arr, newarr), NULL);
		newarr[i + 1] = NULL;
	}
	if (arr)
		free(arr);
	return (newarr);
}

char	**ft_arrremove(char **arr, int pos)
{
	char	**new;
	int		i;
	int		len;

	len = ft_arrlen(arr);
	if (!arr || pos >= len || pos < 0)
		return (arr);
	new = NULL;
	new = malloc(len * sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < pos)
		new[i] = arr[i];
	free(arr[i++]);
	while (arr[i])
	{
		new[i - 1] = arr[i];
		i++;
	}
	new[len - 1] = NULL;
	free(arr);
	return (new);
}
