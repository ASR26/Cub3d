/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflagorder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 07:58:24 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/30 09:13:29 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

const char	*ft_checkflagordsym(const char *str, t_flag *flag)
{
	while (*str == '#' || *str == ' ' || *str == '-' || *str == '0'
		|| *str == '+')
	{
		if (*str == '#')
			(*flag).hash = 1;
		if (*str == ' ')
			(*flag).spc = 1;
		if (*str == '-')
			(*flag).min = 1;
		if (*str == '0')
			(*flag).zero = 1;
		if (*str == '+')
			(*flag).plus = 1;
		str++;
	}
	return (str);
}

const char	*ft_checkflagordwid(const char *str, t_flag *flag)
{
	int		i;
	char	ptr[10];

	if (*str == '*')
		(*flag).wid = -1;
	else
	{
		i = 0;
		while (ft_isdigit(str[i]) == 1)
			i++;
		if (i > 0)
		{
			ft_strlcpy(ptr, (char *)str, i + 1);
			(*flag).wid = ft_atoi(ptr);
		}
		str += i;
	}
	return (str);
}

const char	*ft_checkflagordprec(const char *str, t_flag *flag)
{
	int		i;
	char	ptr[10];

	if (*str == '.')
	{
		str++;
		(*flag).prec = 0;
		if (*str == '*')
			(*flag).prec = -1;
		else
		{
			i = 0;
			while (ft_isdigit(str[i]) == 1)
				i++;
			if (i > 0)
			{
				ft_strlcpy(ptr, (char *)str, i + 1);
				(*flag).prec = ft_atoi(ptr);
			}
			str += i;
		}
	}
	return (str);
}

t_flag	ft_checkflagorder(const char *str, t_flag flag)
{
	str = ft_checkflagordsym(str, &flag);
	str = ft_checkflagordwid(str, &flag);
	str = ft_checkflagordprec(str, &flag);
	if (*str == 'c' || *str == 'd' || *str == 'i'
		|| *str == 'p' || *str == 's' || *str == 'u'
		|| *str == 'x' || *str == 'X' || *str == '%')
	{
		flag.ok = 1;
		flag.conv = *str;
		flag = ft_checkflagconv(flag);
	}
	else
		flag.ok = 0;
	return (flag);
}
