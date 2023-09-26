/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:28:19 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/26 17:28:18 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	c = (char) c;
	if (c < -128 || c > 127)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	else
		return (NULL);
}

/* int main(void)
{
	char sm[] = "hello";
	char sr[] = "hello";
	int c = 'h' + 256;

	write(1, &c, 1);
	printf("Mine %s \n", ft_strchr(sm, c));
	printf("Real %s ", strchr(sr, c));
	return (0);
} */