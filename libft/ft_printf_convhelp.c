/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convhelp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:00:12 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/30 09:11:55 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_conv_prefix(char *ptr, t_flag flag, unsigned int argum)
{
	if (flag.conv == 'x' || flag.conv == 'X')
	{
		if (*ptr == '-')
			return (0);
		else if (flag.hash == 1 && argum != 0)
			return (2);
		else
			return (0);
	}
	if (flag.conv == 'u' || flag.conv == 'd' || flag.conv == 'i')
	{
		if (*ptr == '-')
			return (0);
		else if (flag.plus == 1 || flag.spc == 1)
			return (1);
		else
			return (0);
	}
	return (0);
}

int	ft_conv_zch(char *ptr, t_flag flag, int prefix)
{
	int		zch;
	int		len;

	len = ft_strlen(ptr);
	if (*ptr == '-' && (flag.conv == 'd' || flag.conv == 'i'))
		len--;
	zch = 0;
	if (flag.prec > 0 && len < flag.prec)
		zch = flag.prec - len;
	if (flag.wid != -2 && (flag.zero == 1 && flag.min == 0) && flag.prec == -2)
	{
		if (prefix + zch + (int) ft_strlen(ptr) < flag.wid)
		zch += flag.wid - (prefix + zch + (int) ft_strlen(ptr));
	}
	return (zch);
}
