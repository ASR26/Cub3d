/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:52:53 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/30 09:11:42 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_skipconv(const char *str)
{
	int		skipchr;
	char	ch;

	str++;
	skipchr = 1;
	if (*str == '%')
		return (2);
	ch = *str;
	while (ch == '#' || ch == ' ' || ch == '.' || ch == '-' || ch == 'O'
		|| ch == '+' || ch == '*' || ft_isdigit(ch) == 1)
	{
		str++;
		skipchr++;
		ch = *str;
	}
	if (ch == 'c' || ch == 'd' || ch == 'i' || ch == 'p' || ch == 's'
		|| ch == 'u' || ch == 'x' || ch == 'X' || ch == '%')
		skipchr++;
	return (skipchr);
}

static int	ft_printf_conversion(va_list arglistcpy, t_flag flag)
{	
	int	i;

	i = 0;
	if (flag.conv == '%')
		return (ft_printf_percentage(flag));
	else if (flag.conv == 'c')
		return (ft_printf_convc(va_arg(arglistcpy, int), flag));
	else if (flag.conv == 's')
		return (ft_printf_convs(va_arg(arglistcpy, char *), flag));
	else if (flag.conv == 'p')
		return (ft_printf_convp(va_arg(arglistcpy, void *), flag));
	else if (flag.conv == 'd' || flag.conv == 'i')
		return (ft_printf_convdi(va_arg(arglistcpy, int), flag));
	else if (flag.conv == 'u')
		return (ft_printf_convu(va_arg(arglistcpy, unsigned int), flag));
	else if (flag.conv == 'x' || flag.conv == 'X')
		return (ft_printf_convx(va_arg(arglistcpy, int), flag));
	else
		return (-1);
}

const char	*ft_printf_write(const char *str, int *numptr)
{
	while (*str != '%' && *str)
	{
		write(1, str, 1);
		str++;
		(*numptr)++;
	}
	return (str);
}

int	ft_printf(const char *str, ...)
{
	int		numchr;
	va_list	arglist;
	va_list	arglistcpy;
	t_flag	flag;

	va_start(arglist, str);
	numchr = 0;
	while (*str)
	{
		str = ft_printf_write(str, &numchr);
		if (*str && *(str + 1))
		{
			flag = ft_checkflag(str);
			if (flag.ok == 0)
				return (-1);
			va_copy(arglistcpy, arglist);
			numchr += ft_printf_conversion(arglistcpy, flag);
			if (flag.conv != '%')
				va_arg(arglist, void *);
			str += ft_skipconv(str);
		}
	}
	va_end(arglist);
	return (numchr);
}

/* int main(void)
{
	//ft_printf("%i\n", 24);
	//ft_printf(" NULL %s NULL ", NULL);
	//printf("\n NULL %s NULL ", NULL);
	//ft_printf("%c", '0');
	//printf("%c", '0');
	ft_printf("ft_printf\001\002\007\v\010\f\r\n");
	printf("...printf: %p", -564);
} */
