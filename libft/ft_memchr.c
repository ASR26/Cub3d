/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:54:49 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 12:41:12 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;

	c = (char) c;
	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

/* int main(void)
{
	char sm[] = "hello";
	char sr[] = "hello";
	int c = 0;
	int n = 6;

	printf("Mine %s \n", ft_memchr(sm, c, n));
	printf("Real %s", memchr(sr, c, n));
	return (0);
} */