/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflagconv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:00:32 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/30 09:13:24 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

t_flag	ft_checkflagconvcidux(t_flag flag)
{
	char	ch;

	ch = flag.conv;
	if (ch == 'c')
	{
		if (flag.zero == 1 || flag.spc == 1 || flag.plus == 1 || flag.hash == 1)
			flag.ok = 0;
	}
	if (ch == 'i' || ch == 'd')
	{
		if (flag.hash == 1)
			flag.ok = 0;
	}
	if (ch == 'u')
	{
		if (flag.spc == 1 || flag.plus == 1 || flag.hash == 1)
			flag.ok = 0;
	}
	if (ch == 'x' || ch == 'X')
	{
		if (flag.spc == 1 || flag.plus == 1)
			flag.ok = 0;
	}
	return (flag);
}

t_flag	ft_checkflagconv(t_flag flag)
{
	char	ch;

	if (flag.zero == 1 && flag.min == 1)
		flag.zero = 0;
	if (flag.spc == 1 && flag.plus == 1)
		flag.spc = 0;
	ch = flag.conv;
	flag = ft_checkflagconvcidux(flag);
	if (ch == 's')
	{
		if (flag.zero == 1 || flag.plus == 1 || flag.hash == 1)
			flag.ok = 0;
	}
	if (ch == '%')
	{
		flag.ok = 1;
	}
	if (ch == 'p')
	{
		if (flag.zero == 1 || flag.spc == 1 || flag.plus == 1
			|| flag.hash == 1 || flag.prec != -2)
			flag.ok = 0;
	}
	return (flag);
}
