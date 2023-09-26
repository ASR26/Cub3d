/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:46:00 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/19 17:59:50 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/* int main()
{
	int c;

	c = 0;
	while (c < 130)
	{
		printf("Mine %i \n", ft_isascii(c));
		printf("Real %i \n", isascii(c));
		c++;
	}
	return(0);
} */