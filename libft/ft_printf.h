/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:42:00 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/25 08:00:52 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_flag
{
	int		ok;
	int		min;
	int		zero;
	int		spc;
	int		plus;
	int		hash;
	int		wid;
	int		prec;
	char	conv;
}		t_flag;

typedef struct s_pre
{
	int	prefix;
	int	zch;
}			t_pre;

int		ft_printf(const char *str, ...);
int		ft_printf_convc(char argum, t_flag flag);
int		ft_printf_convdi(int argum, t_flag flag);
int		ft_printf_convp(void *argum, t_flag flag);
int		ft_printf_convs(char *argum, t_flag flag);
int		ft_printf_convu(unsigned int argum, t_flag flag);
int		ft_printf_convx(unsigned int argum, t_flag flag);
t_flag	ft_checkflag(const char *str);
int		ft_printf_percentage(t_flag flag);
char	*ft_ltoa(long n);
char	*ft_ltohex(unsigned long num, char cap);
char	*ft_lltohex(unsigned long long num, char cap);
int		ft_conv_zch(char *ptr, t_flag flag, int prefix);
int		ft_conv_prefix(char *ptr, t_flag flag, unsigned int argum);
t_flag	ft_checkflagorder(const char *str, t_flag flag);
t_flag	ft_checkflagconv(t_flag flag);

#endif