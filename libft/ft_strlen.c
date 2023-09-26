/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:55:42 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/19 18:03:23 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* int main()
{
	char c[] = "hello";
	
	ft_strlen(c);
	printf("Mine %lu \n", ft_strlen(c));
	printf("Real %lu", strlen(c));
	return(0);
} */