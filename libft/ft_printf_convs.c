/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:41:29 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/30 09:12:18 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_printf_cons_pre(t_flag flag, int len)
{
	int	addchr;
	int	i;

	addchr = 0;
	if (flag.wid > -1 && len < flag.wid && flag.min == 0)
	{
		i = 0;
		while (i < flag.wid - len)
		{
			ft_putchar_fd(' ', 1);
			i++;
			addchr++;
		}
	}
	return (addchr);
}

int	ft_printf_cons_mid(char *argum, t_flag flag, int len)
{
	int	addchr;
	int	i;

	addchr = 0;
	if (argum == NULL)
	{
		i = 6;
		if (flag.prec > -1 && flag.prec < 6)
			i = flag.prec;
		write(1, "(null)", i);
		addchr += i;
	}
	else
	{
		i = 0;
		while (i < len)
		{
			ft_putchar_fd(argum[i], 1);
			addchr++;
			i++;
		}
	}
	return (addchr);
}

int	ft_printf_convs(char *argum, t_flag flag)
{
	int	addchr;
	int	len;
	int	i;

	addchr = 0;
	if (argum)
		len = ft_strlen(argum);
	else
		len = 6;
	if (flag.prec > -1 && len > flag.prec)
		len = flag.prec;
	addchr += ft_printf_cons_pre(flag, len);
	addchr += ft_printf_cons_mid(argum, flag, len);
	if (flag.wid > -1 && len < flag.wid && flag.min == 1)
	{
		i = 0;
		while (i < flag.wid - len)
		{
			ft_putchar_fd(' ', 1);
			i++;
			addchr++;
		}
	}
	return (addchr);
}
