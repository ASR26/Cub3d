/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:31:52 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 14:01:18 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include <stdlib.h>
#include "libft.h"

static char	*ft_substrempty(char *ptr)
{
	if (ptr)
	{
		ptr[0] = 0;
	}
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*ptr;
	unsigned int		count;
	unsigned int		strlen;

	strlen = ft_strlen(s);
	if (start > strlen)
	{
		ptr = malloc(sizeof(char));
		return (ft_substrempty(ptr));
	}
	if (len > strlen - start)
		len = strlen - start;
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr)
	{
		count = 0;
		while (count < len && s[start + count])
		{
			ptr[count] = s[start + count];
			count++;
		}
		ptr[count] = 0;
	}
	return (ptr);
}

/* int main(void)
{
	char str[] = "abcdef";
	int start = 10;
	int len = 5;

	printf("%s", ft_substr(str, start, len));
	return (0);
} */