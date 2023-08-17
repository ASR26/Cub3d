/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:51:29 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 13:35:40 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned int	count;
	int				i;

	count = 0;
	i = 0;
	while (count < n && *s1 + *s2 != 0)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
		{
			i = (unsigned char) *s1 - (unsigned char) *s2;
			break ;
		}
		count++;
	}
	return (i);
}

/* int main(void)
{
	char l[] = "abcdef";
	char r[] = "abc\375xx";

	int real;
	int mine;

	write(1, "test\375", 6);
	int i = '\375';
	printf("\n i is %d\n", i);

	real = strncmp("abcdef", "abc\375xx", 5);
	mine = ft_strncmp(r, l, 5);

	printf("%d\n", real);
	printf("%d", mine);
} */