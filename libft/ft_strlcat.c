/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:45:37 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/19 18:28:50 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	sizedest;
	unsigned int	sizesrc;
	unsigned int	count;
	unsigned int	n;

	sizedest = ft_strlen(dest);
	sizesrc = ft_strlen(src);
	if (size > sizedest)
	{
		n = size - sizedest - 1;
		count = 0;
		dest = dest + sizedest;
		while (count++ < n && *src != 0)
		{
			*dest = *src;
			src++;
			dest++;
		}
		*dest = 0;
		return (sizedest + sizesrc);
	}
	else if (size == sizedest)
		return (sizedest + sizesrc);
	else
		return (sizedest + sizesrc - (sizedest - size));
}
