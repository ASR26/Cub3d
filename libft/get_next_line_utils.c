/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:10:11 by ysmeding          #+#    #+#             */
/*   Updated: 2023/05/14 16:34:31 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <libc.h>
#include "get_next_line.h"

void	ft_set_restbuf(char *buf, int i)
{
	while (i < BUFFER_SIZE)
	{
		buf[i] = 0;
		i++;
	}
}

char	*ft_cpy_new_to_old(char *ptr_new, int *len)
{
	char	*ptr_old;
	int		i;

	(*len) = 0;
	while (ptr_new[(*len)])
		(*len)++;
	ptr_old = malloc(((*len) + 1) * sizeof(char));
	if (ptr_old)
	{
		i = 0;
		while (i < (*len))
		{
			ptr_old[i] = ptr_new[i];
			i++;
		}
		ptr_old[i] = 0;
		free(ptr_new);
	}
	else
	{
		free(ptr_new);
		return (NULL);
	}
	return (ptr_old);
}

int	ft_find_nl(char *str, int *nl)
{
	int	i;

	i = 0;
	if (str)
	{
		while (i < BUFFER_SIZE && str[i] && str[i] != '\n')
			i++;
		if (i < BUFFER_SIZE && str[i] == '\n')
		{
			*nl = 1;
			i++;
		}	
	}
	return (i);
}
