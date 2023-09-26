/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:49:44 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 11:43:01 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	if (dest || src)
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/* int main()
{
	//char sm[] = "1st string";
	//char dm[] = "2nd string";
	//char sr[] = "1st string";
	//char dr[] = "2nd string";
	//char sm2[] = "hello how are you?";
	//char sr2[] = "hello how are you?";

	printf("Mine %s \n", ft_memcpy(NULL, NULL, 12));
	printf("Real %s", memcpy(NULL, NULL, 12));
	return(0);
} */