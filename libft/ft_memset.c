/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:29:56 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/19 18:05:44 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include <unistd.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* int main()
{
	//char sm[] = "hello how are you?";
	//char sr[] = "hello how are you?";
	void *sm[10];
	void *sr[10];

	printf("Mine %s \n", ft_memset(sm, '.', 5));
	printf("Real %s", memset(sr, '.', (5)));
	return(0);
} */