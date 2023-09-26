/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:41:47 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/30 09:13:20 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

t_flag	ft_checkflag(const char *str)
{
	t_flag	flag;

	flag.ok = 0;
	flag.min = 0;
	flag.zero = 0;
	flag.spc = 0;
	flag.plus = 0;
	flag.hash = 0;
	flag.wid = -2;
	flag.prec = -2;
	flag.conv = 0;
	str++;
	if (*str != 'c' && *str != 'd' && *str != 'i'
		&& *str != 'p' && *str != 's' && *str != 'u'
		&& *str != 'x' && *str != 'X')
	{
		flag = ft_checkflagorder(str, flag);
	}
	else
	{
		flag.ok = 1;
		flag.conv = *str;
	}
	return (flag);
}
