/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:41:56 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/30 09:12:26 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_conp_zch(char *ptr, t_flag flag, int prefix)
{
	int		zch;

	zch = 0;
	if (flag.prec > 0 && (int) ft_strlen(ptr) < flag.prec)
		zch = flag.prec - (int) ft_strlen(ptr);
	if (flag.wid != -2 && (flag.zero == 1 && flag.min == 0))
	{
		if (prefix + zch + (int) ft_strlen(ptr) < flag.wid)
		zch += flag.wid - (prefix + zch + (int) ft_strlen(ptr));
	}
	return (zch);
}

int	ft_printf_convp_pre(t_flag flag, int zch, char *ptr)
{
	int	addchr;
	int	i;

	addchr = 0;
	if (flag.wid >= 0 && flag.zero == 0 && flag.min == 0)
	{
		i = 0;
		while (i < (flag.wid - (2 + zch + (int) ft_strlen(ptr))))
		{
			ft_putchar_fd(' ', 1);
			addchr++;
			i++;
		}
	}
	write(1, "0x", 2);
	addchr += 2;
	i = 0;
	while (i < zch)
	{
		ft_putchar_fd('0', 1);
		i++;
		addchr++;
	}
	return (addchr);
}

int	ft_printf_convp(void *argum, t_flag flag)
{
	int		addchr;
	char	*ptr;
	int		i;
	int		zch;

	addchr = 0;
	ptr = ft_lltohex((unsigned long long) argum, flag.conv);
	if (ptr)
	{
		zch = ft_conp_zch(ptr, flag, 2);
		addchr += ft_printf_convp_pre(flag, zch, ptr) + ft_strlen(ptr);
		ft_putstr_fd(ptr, 1);
		if (flag.wid >= 0 && flag.min == 1)
		{
			i = 0;
			while (i < (flag.wid - (2 + zch + (int) ft_strlen(ptr))))
			{
				ft_putchar_fd(' ', 1);
				addchr++;
				i++;
			}
		}
		free(ptr);
	}
	return (addchr);
}
