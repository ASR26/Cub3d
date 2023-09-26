/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:51:58 by ysmeding          #+#    #+#             */
/*   Updated: 2023/08/14 13:51:08 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static unsigned int	ft_begin_count(char const *s1, char const *set)
{
	int	begin;
	int	count;
	int	i;

	count = 0;
	while (s1[count])
	{
		i = 0;
		begin = 0;
		while (set[i])
		{
			if (s1[count] == set[i])
			{
				begin = 1;
				break ;
			}
			i++;
		}
		if (begin == 1)
			count++;
		else
			break ;
	}
	return (count);
}

static unsigned int	ft_end_count(char const *s1, char const *set, int len)
{
	int	end;
	int	count;
	int	i;

	count = 0;
	while (count < len)
	{
		i = 0;
		end = 0;
		while (set[i])
		{
			if (s1[len - count - 1] == set[i])
			{
				end = 1;
				break ;
			}
			i++;
		}
		if (end == 1)
			count++;
		else
			break ;
	}
	return (count);
}

static char	*ft_strtrimempty(char *ptr)
{
	if (ptr)
	{
		ptr[0] = 0;
	}
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int		begin;
	unsigned int		end;
	unsigned int		i;
	char				*ptr;

	begin = ft_begin_count(s1, set);
	end = ft_end_count(s1, set, ft_strlen(s1));
	if (begin == ft_strlen(s1))
	{
		ptr = malloc(sizeof(char));
		return (ft_strtrimempty(ptr));
	}
	ptr = malloc((ft_strlen(s1) - begin - end + 1) * sizeof(char));
	if (ptr)
	{
		i = 0;
		while (i < ft_strlen(s1) - begin - end)
		{
			ptr[i] = s1[begin + i];
			i++;
		}
		ptr[i] = 0;
	}
	return (ptr);
}

/* int main(void)
{
	char str[] = "";
	char set[] = "cdef";

	printf("trimmed string is %s", ft_strtrim(str, set));
	return (0);
} */