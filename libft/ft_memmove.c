/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:03:36 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 13:42:02 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include <unistd.h>

static void	*ft_memmove_end(void *dest, const void *src, size_t n)
{
	while (n)
	{
		((char *)dest)[n - 1] = ((char *)src)[n - 1];
		n--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		i;

	i = 0;
	if (dest || src)
	{
		while (i < n)
		{
			if ((src + i) == dest)
				break ;
			i++;
		}
		if (i < n)
			return (ft_memmove_end(dest, src, n));
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/* int main(void)
{
	char sm[] = "hello how are you?";
	char sr[] = "hello how are you?";
	//char sr2[] = "hello how are you?";

	printf("Mine %s \n", ft_memmove( sm+1, sm, 13));
	printf("Real %s\n", memmove( sr+1,  sr, 13));
	//printf("Real %s", memcpy( sr2+1,  sr2, 17));
	return (0);
} */