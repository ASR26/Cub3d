/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:36:56 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/30 09:11:03 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_printf_convc_pre(t_flag flag)
{
	int	addchr;

	addchr = 0;
	if (flag.wid > 0 && flag.min == 0)
	{
		while (flag.wid > 1)
		{
			ft_putchar_fd(' ', 1);
			addchr++;
			flag.wid--;
		}
	}
	return (addchr);
}

int	ft_printf_convc(char argum, t_flag flag)
{
	int	addchr;
	int	i;

	addchr = 0;
	addchr += ft_printf_convc_pre(flag);
	ft_putchar_fd(argum, 1);
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
