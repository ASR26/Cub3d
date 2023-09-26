/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:43:42 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 12:40:39 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		found;

	c = (char) c;
	found = 0;
	while (*s)
	{
		if (*s == c)
		{
			ptr = (char *)s;
			found = 1;
		}	
		s++;
	}
	if (*s == c)
	{
		ptr = (char *)s;
		found = 1;
	}
	if (found == 1)
		return (ptr);
	else
		return (NULL);
}

/* int main(void)
{
	char sm[] = "hello";
	char sr[] = "hello";
	char c = 'a';

	printf("Mine %s \n", ft_strrchr(sm, c));
	printf("Real %s ", strrchr(sr, c));
	return (0);
} */