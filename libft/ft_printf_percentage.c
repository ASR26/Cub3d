/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:27:23 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/30 09:12:01 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_printf_percentagepre(t_flag flag)
{
	int	addchr;

	addchr = 0;
	if (flag.wid > 0 && flag.min == 0)
	{
		while (flag.wid > 1)
		{
			if (flag.zero == 1)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			addchr++;
			flag.wid--;
		}
	}
	return (addchr);
}

int	ft_printf_percentage(t_flag flag)
{
	int	addchr;
	int	i;

	addchr = 0;
	addchr += ft_printf_percentagepre(flag);
	ft_putchar_fd('%', 1);
	addchr++;
	if (flag.wid > 0 && flag.min == 1)
	{
		i = 0;
		while (i < flag.wid - 1)
		{
			ft_putchar_fd(' ', 1);
			i++;
			addchr++;
		}
	}
	return (addchr);
}
