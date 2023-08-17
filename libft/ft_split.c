/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:42:09 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/30 09:38:54 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_numstr(char const *s, char c)
{
	int		numstr;
	int		i;

	numstr = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			numstr++;
		i++;
	}
	if (s[i - 1] == c)
		numstr--;
	return (numstr);
}

static char	**ft_freearrstr(char **arrstr, int strindex)
{
	int	i;

	i = 0;
	while (i < strindex)
	{
		free(arrstr[i]);
		i++;
	}
	free(arrstr);
	return (NULL);
}

int	ft_wordlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

char	**ft_arrstrfill(char **arrstr, const char *s, char c, int strindex)
{
	int	i;

	while (*s)
	{
		arrstr[strindex] = malloc((ft_wordlen(s, c) + 1) * sizeof(char));
		if (arrstr[strindex])
		{
			i = 0;
			while (i < ft_wordlen(s, c))
			{
				arrstr[strindex][i] = s[i];
				i++;
			}
			arrstr[strindex][i] = 0;
			if (*s)
				strindex++;
			s += ft_wordlen(s, c);
			while (*s == c && c != 0)
				s++;
		}
		else
			return (ft_freearrstr(arrstr, strindex));
	}
	arrstr[strindex] = NULL;
	return (arrstr);
}

char	**ft_split(char const *s, char c)
{
	char	**arrstr;
	int		numstr;
	int		strindex;

	if (s == 0 || *s == 0)
	{
		arrstr = malloc(sizeof(char *));
		if (arrstr)
			arrstr[0] = NULL;
		return (arrstr);
	}
	numstr = ft_numstr(s, c);
	arrstr = malloc((numstr + 2) * sizeof(char *));
	strindex = 0;
	while (*s == c)
		s++;
	if (arrstr)
		arrstr = ft_arrstrfill(arrstr, s, c, strindex);
	return (arrstr);
}

/* int main(void)
{
	int i = 0;

	printf("%s\n", ft_split("hello!zzzzzzzz", 'z')[i]);
	return(0);
} */