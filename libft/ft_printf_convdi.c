/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convdi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:42:18 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/30 09:11:37 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_printf_convdipre(t_flag flag, t_pre pre, int argum, char *ptr)
{
	int	addchr;
	int	i;

	addchr = 0;
	if (flag.wid >= 0 && (flag.zero == 0 || flag.prec != -2) && flag.min == 0)
	{
		i = 0;
		while (i < (flag.wid - (pre.prefix + pre.zch + (int) ft_strlen(ptr))))
		{
			ft_putchar_fd(' ', 1);
			addchr++;
			i++;
		}
		if (flag.prec == 0 && argum == 0 && i < (flag.wid
				- (pre.prefix + pre.zch + (int) ft_strlen(ptr) - 1)))
		{
			ft_putchar_fd(' ', 1);
			addchr++;
		}
	}
	return (addchr);
}

int	ft_printf_convdimid1(t_flag flag, int argum)
{
	int	addchr;

	addchr = 0;
	if (flag.plus == 1)
	{
		if (argum >= 0)
		{
			ft_putchar_fd('+', 1);
			addchr++;
		}
	}
	if (flag.spc == 1 && flag.plus == 0)
	{
		if (argum >= 0)
		{
			ft_putchar_fd(' ', 1);
			addchr++;
		}
	}
	return (addchr);
}

int	ft_printf_mid2(t_flag flag, t_pre pre, int argum, char *ptr)
{
	int	addchr;
	int	i;

	addchr = 0;
	if (argum < 0)
	{
		ft_putchar_fd(ptr[0], 1);
		ptr++;
		addchr++;
	}
	i = 0;
	while (i < pre.zch)
	{
		ft_putchar_fd('0', 1);
		i++;
		addchr++;
	}
	if (!(flag.prec == 0 && argum == 0))
	{
		ft_putstr_fd(ptr, 1);
		addchr += ft_strlen(ptr);
	}
	return (addchr);
}

int	ft_printf_convdipost(t_flag flag, t_pre pre, int argum, char *ptr)
{
	int	addchr;
	int	i;

	addchr = 0;
	if (flag.wid >= 0 && flag.min == 1)
	{
		i = 0;
		while (i < (flag.wid - (pre.prefix + pre.zch + (int) ft_strlen(ptr))))
		{
			ft_putchar_fd(' ', 1);
			addchr++;
			i++;
		}
		if (flag.prec == 0 && argum == 0 && i < (flag.wid
				- (pre.prefix + pre.zch + (int) ft_strlen(ptr) - 1)))
		{
			ft_putchar_fd(' ', 1);
			addchr++;
		}
	}
	return (addchr);
}

int	ft_printf_convdi(int argum, t_flag flag)
{
	int		addchr;
	char	*ptr;
	t_pre	pre;

	addchr = 0;
	ptr = ft_itoa(argum);
	if (ptr)
	{
		pre.prefix = ft_conv_prefix(ptr, flag, argum);
		pre.zch = ft_conv_zch(ptr, flag, pre.prefix);
		addchr += ft_printf_convdipre(flag, pre, argum, ptr);
		addchr += ft_printf_convdimid1(flag, argum);
		addchr += ft_printf_mid2(flag, pre, argum, ptr);
		addchr += ft_printf_convdipost(flag, pre, argum, ptr);
		free(ptr);
	}
	else
		return (-1);
	return (addchr);
}
