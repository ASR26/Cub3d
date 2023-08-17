/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:38:12 by ysmeding          #+#    #+#             */
/*   Updated: 2023/05/05 11:38:38 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

static int	ft_len(long n)
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

static char	*ft_ltoa_pos(char *ptr, long n, int len, int index)
{
	while (len > index)
	{
		ptr[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (ptr);
}

char	*ft_ltoa(long n)
{
	char	*ptr;
	int		index;
	int		len;

	index = 0;
	len = ft_len(n);
	ptr = ft_calloc((len + 1), sizeof(char));
	if (ptr)
	{
		ptr[len] = 0;
		if (n < 0)
		{
			ptr[0] = '-';
			n = -n;
			index++;
		}
		ptr = ft_ltoa_pos(ptr, n, len, index);
	}
	return (ptr);
}
