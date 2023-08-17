/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:53:47 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 08:13:07 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/* #include <stdio.h> */

static int	ft_len(int n)
{
	int	len;
	int	i;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	len = 0;
	i = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n >= 1000000000)
		return (10 + len);
	while (n / i >= 1)
	{
		len++;
		i = i * 10;
	}
	if (n == 0)
		len = 1;
	return (len);
}

static char	*ft_itoa_pos(char *ptr, int n, int len, int index)
{
	while (len > index)
	{
		ptr[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		index;
	int		len;

	index = 0;
	len = ft_len(n);
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr)
	{
		ptr[len] = 0;
		if (n == -2147483648)
		{
			ptr[10] = 8 + '0';
			n = n / 10;
			len--;
		}
		if (n < 0)
		{
			ptr[0] = '-';
			n = -n;
			index++;
		}
		ptr = ft_itoa_pos(ptr, n, len, index);
	}
	return (ptr);
}

/* int main(void)
{
	int nbr = -2147483648;

	printf("number is %s", ft_itoa(nbr));
	return (0);
} */