/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:10:53 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/30 09:13:04 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

char	*ft_itohex_assign(char *ptr, int i, long digitlist[20], char cap)
{
	int	j;
	int	capt;

	j = 0;
	if (cap == 'X')
		capt = -32;
	else
		capt = 0;
	while (j < i)
	{
		if (digitlist[i - 1 - j] <= 9)
			ptr[j] = digitlist[i - 1 - j] + '0';
		else if (digitlist[i - 1 - j] <= 15)
			ptr[j] = (digitlist[i - 1 - j] - 10) + 'a' + capt;
		else
			ptr[j] = '-';
		j++;
	}
	return (ptr);
}

char	*ft_ltohex(unsigned long num, char cap)
{
	int		i;
	long	digit;
	long	digitlist[20];
	char	*ptr;

	i = 0;
	if (num == 0)
	{
		digitlist[0] = 0;
		i = 1;
	}
	while (num > 0 && i < 8)
	{
		digit = num % 16;
		digitlist[i] = digit;
		num = num / 16;
		i++;
	}
	ptr = ft_calloc((i + 1), sizeof(char));
	if (ptr)
	{
		ptr = ft_itohex_assign(ptr, i, digitlist, cap);
	}
	return (ptr);
}
