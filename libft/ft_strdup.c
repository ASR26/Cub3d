/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:23:25 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 14:05:12 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		len;
	char	*ptr;
	int		i;

	len = 0;
	while (src[len])
		len ++;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr)
	{
		i = 0;
		while (src[i])
		{
			ptr[i] = src[i];
			i++;
		}
		ptr[i] = src[i];
	}
	return (ptr);
}

/* int main()
{
	char str[] = "I'm tired.";
	//char str[] = "";

	printf("real: %s\n", strdup(str));
	printf("mine: %s", ft_strdup(str));
} */