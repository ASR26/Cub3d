/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:35:37 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 13:11:06 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int				i;
	int				found;
	unsigned int	count;

	found = 0;
	count = 0;
	if (*s2 == 0)
		return ((char *)s1);
	while (count < n && s1[count])
	{
		i = 0;
		while (s1[count + i] == s2[i] && found == 0
			&& count + i < n && s1[count + i])
		{
			i++;
			if (s2[i] == 0)
				found = 1;
		}
		if (found == 1)
			return ((char *)s1 + count);
		else
			count++;
	}
	return (NULL);
}

/* int main(void)
{
	char s1[] = "abc";
	char s2[] = "r";

	//printf("Mine %s \n", ft_strnstr("", "coucou", -1));
	//printf("Real %s ", strnstr("", "coucou", -1));
	printf("Mine %s \n", ft_strnstr(s1, s2, -1));
	printf("Real %s ", strnstr(s1, s2, -1));
} */