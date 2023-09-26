/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:10:54 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 12:47:11 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	count;

	count = 0;
	while (count < n)
	{
		if (((unsigned char *)s1)[count] != ((unsigned char *)s2)[count])
		{
			if (((unsigned char *)s1)[count] < 0
			|| ((unsigned char *)s2)[count] < 0)
				return (1);
			return (((unsigned char *)s1)[count]
			- ((unsigned char *)s2)[count]);
		}
		count++;
	}
	return (0);
}

/* int main(void)
{
	//char s1[] = "hello.";
	//char s2[] = "hello!";

	printf("Mine %d \n", ft_memcmp("t\200", "t\0", 2));
	printf("Real %d \n", memcmp("t\200", "t\0", 2));
	return(0);
} */