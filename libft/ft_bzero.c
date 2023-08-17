/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:42:15 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/19 18:10:37 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <strings.h>
#include <stdio.h> */
#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

/* int main()
{
	char sm[] = "hello how are you?";
	char sr[] = "hello how are you?";
	//void *sm[15];
	//void *sr[15];
	int x = 5;

	ft_bzero(sm, 5);
	bzero(sr, 5);

	printf("Mine %s \n", sm+x);
	printf("Real %s", sr+x);
	return(0);
} */