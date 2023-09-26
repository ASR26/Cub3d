/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:26:09 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 08:19:33 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr_pos_fd(int n, int fd)
{
	char	c;

	if (n > 9)
		ft_putnbr_pos_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		n = n / 10;
		ft_putnbr_pos_fd(-n, fd);
		write(fd, "8", 1);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_pos_fd(-n, fd);
	}
	else
		ft_putnbr_pos_fd(n, fd);
}

/* int main()
{
	ft_putnbr_fd(0, 1);
} */