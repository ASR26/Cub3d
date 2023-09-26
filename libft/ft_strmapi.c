/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:30:21 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 12:02:47 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*ptr;
	unsigned int		len;
	unsigned int		index;

	len = 0;
	while (s[len])
		len++;
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr)
	{
		index = 0;
		while (index < len)
		{
			ptr[index] = f(index, s[index]);
			index++;
		}
		ptr[index] = 0;
	}
	return (ptr);
}
