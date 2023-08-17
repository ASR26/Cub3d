/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:42:43 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 08:48:32 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include <unistd.h>

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	while (i < size - 1 && src[i] != 0)
	{
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = 0;
	return (len);
}

/* int main()
{
	//char str1[50] = "Bonjour";
	//char str2[] = "Salut les amis";
	//char str3[50] = "Bonjour";
	//char str4[] = "Salut les amis";
	char dest[15];
	char dest1[15];

	unsigned int a;
	unsigned int b;
	//int x;

	//x = 14;
	//printf("%s\n", str1);
	//printf("%s\n", str3);
	a = strlcpy(dest1, "lorem ipsum dolor sit amet", 0);
	b = ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0);

	//if (*(str2 + x) == 0)
		//printf("It's null\n");
	//if (*(str4 + x) == 0)
		//printf("It's also null\n");
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%s\n", dest);
	printf("%s\n", dest);
  	return 0;
} */