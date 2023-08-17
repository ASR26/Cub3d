/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:28:41 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 09:48:05 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdlib.h>
#include <stdio.h> */

int	ft_atoi(const char *nptr)
{
	int	minus;
	int	num;

	minus = 1;
	num = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		minus = -*nptr + 44;
		nptr++;
	}
	if (*nptr < 48 || *nptr > 57)
		return (0);
	while (*nptr >= 48 && *nptr <= 57)
	{
		num = num * 10 + (*nptr - 48);
		nptr++;
	}
	return (minus * num);
}

/* int main(void)
{
	char a[] = "\t\n\r\v\f  469 \n";

	printf("Mine %d\n", ft_atoi(a));
	printf("Real %d", atoi(a));
} */