/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:59:17 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 08:39:57 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		len;
	unsigned int		index;

	len = 0;
	while (s[len])
		len++;
	index = 0;
	while (index < len)
	{
		f(index, s + index);
		index++;
	}
}
