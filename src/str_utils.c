/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:34:55 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 14:40:11 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*ft_substrfree(char *str, unsigned int start, size_t len)
{
	char	*substr;

	substr = ft_substr(str, start, len);
	free(str);
	return (substr);
}

char	*ft_strjoinfree(char *begin, char *end, int num)
{
	char	*new;

	new = ft_strjoin(begin, end);
	if (num == 1 || num == 3)
		free(begin);
	if (num == 2 || num == 3)
		free(end);
	return (new);
}

int	ft_strchr_r(const char *str, char *check)
{
	int	i[2];

	i[0] = -1;
	if (!str)
		return (-1);
	while (str[++i[0]])
	{
		i[1] = -1;
		while (check[++i[1]])
		{
			if (str[i[0]] == check[i[1]])
				return (i[0]);
		}
	}
	return (-1);
}

int	ft_strchr_i(const char *s, int c)
{
	unsigned char	u_char;
	int				i;

	i = 0;
	if (!s)
		return (-1);
	u_char = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == u_char)
			return (i);
		i++;
	}
	if (u_char == '\0')
		return (i);
	return (-1);
}
