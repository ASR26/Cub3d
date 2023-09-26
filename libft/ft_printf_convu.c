/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:43:04 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/30 09:12:12 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

static int	ft_printf_convu_pre(int argum, t_flag flag, t_pre pre, char *ptr)
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
		if (flag.prec == 0 && argum == 0)
		{
			ft_putchar_fd(' ', 1);
			addchr++;
		}
	}
	return (addchr);
}

static int	ft_printf_convu_mid(t_pre pre)
{
	int	addchr;
	int	i;

	addchr = 0;
	i = 0;
	while (i < pre.zch)
	{
		ft_putchar_fd('0', 1);
		i++;
		addchr++;
	}
	return (addchr);
}

static int	ft_printf_convu_post(int argum, t_flag flag, t_pre pre, char *ptr)
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
		if (flag.prec == 0 && argum == 0)
		{
			ft_putchar_fd(' ', 1);
			addchr++;
		}
	}
	return (addchr);
}

int	ft_printf_convu(unsigned int argum, t_flag flag)
{
	int		addchr;
	char	*ptr;
	t_pre	pre;

	addchr = 0;
	ptr = ft_ltoa(argum);
	if (ptr)
	{
		pre.prefix = ft_conv_prefix(ptr, flag, argum);
		pre.zch = ft_conv_zch(ptr, flag, pre.prefix);
		addchr += ft_printf_convu_pre(argum, flag, pre, ptr);
		addchr += ft_printf_convu_mid(pre);
		if (!(flag.prec == 0 && argum == 0))
		{
			ft_putstr_fd(ptr, 1);
			addchr += ft_strlen(ptr);
		}
		addchr += ft_printf_convu_post(argum, flag, pre, ptr);
		free(ptr);
	}
	else
		return (-1);
	return (addchr);
}
