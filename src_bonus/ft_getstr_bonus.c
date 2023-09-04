/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:56:52 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/04 13:10:11 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	ft_findchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_straddfree(char *str, char chr)
{
	char	*new;
	int		len;
	int		i;

	if (!str)
		len = 0;
	else
		len = ft_strlen(str);
	new = malloc((len + 2) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = chr;
	new[++i] = 0;
	if (str)
		free(str);
	return (new);
}

int	ft_addwhilenotchar(char *line, char **name, char c)
{
	int	len;

	len = 0;
	*name = ft_straddfree(*name, line[len]);
	if (!*name)
		return (0);
	len++;
	while (line[len] != c)
	{
		*name = ft_straddfree(*name, line[len]);
		if (!*name)
			return (0);
		len++;
	}
	*name = ft_straddfree(*name, line[len]);
	if (!*name)
		return (0);
	len++;
	return (len);
}

char	*ft_getstr(char *line, int len, int *total)
{
	char	*name;

	name = NULL;
	while (line[len] && line[len] <= 32)
		len++;
	while ((line[len] > 32))
	{
		if (line[len] == '\"' && ft_findchar(&line[len + 1], '\"'))
			len += ft_addwhilenotchar(line + len, &name, '\"');
		else if (line[len] == '\'' && ft_findchar(&line[len + 1], '\''))
			len += ft_addwhilenotchar(line + len, &name, '\'');
		else
		{
			name = ft_straddfree(name, line[len]);
			len++;
		}
		if (!name)
			return (NULL);
	}
	*total = len;
	if (name == NULL)
		return (ft_strdup(""));
	return (name);
}
