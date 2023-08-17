/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:13:29 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 12:15:44 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include <stdlib.h>
#include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*ptr;
	unsigned int		i;

	ptr = malloc(nmemb * size);
	if (ptr)
	{
		i = 0;
		while (i < nmemb * size)
		{
			((char *)ptr)[i] = 0;
			i++;
		}
	}
	return (ptr);
}
