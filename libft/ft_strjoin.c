/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:08:18 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 07:51:26 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*ptr;
	unsigned int		count;
	int					offset;

	count = 0;
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ptr)
	{
		while (count < ft_strlen(s1))
		{
			ptr[count] = s1[count];
			count++;
		}
		offset = count;
		count = 0;
		while (count < ft_strlen(s2))
		{
			ptr[offset + count] = s2[count];
			count++;
		}
		ptr[offset + count] = 0;
	}
	return (ptr);
}

/* int main(void)
{
	char s1[] = "This is the first part ";
	char s2[] = "and this is the second part.";

	printf("%s", ft_strjoin(s1, s2));
	return (0);
} */