/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:34:55 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/01 09:54:27 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

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