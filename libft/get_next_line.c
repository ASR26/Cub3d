/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:10:16 by ysmeding          #+#    #+#             */
/*   Updated: 2023/05/14 16:33:25 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <libc.h>
#include "get_next_line.h"

char	*ft_first_assign_new(char buf[BUFFER_SIZE], int *reads)
{
	int		n;
	int		i;
	char	*ptr_new;

	if (buf[0] != 0)
	{
		n = 0;
		while (n < BUFFER_SIZE && buf[n])
			n++;
		ptr_new = malloc((n + 1) * sizeof(char));
		if (ptr_new)
		{
			i = 0;
			while (i < n)
			{
				ptr_new[i] = buf[i];
				i++;
			}
			ptr_new[i] = 0;
		}
		(*reads)++;
	}
	else
		ptr_new = NULL;
	return (ptr_new);
}

char	*ft_return_new_with_nl(char *ptr_old, char *ptr_new, int n, char *buf)
{
	int	i;
	int	len;

	ptr_old = ft_cpy_new_to_old(ptr_new, &len);
	if (!ptr_old)
		return (NULL);
	ptr_new = malloc((n + 1) * sizeof(char));
	if (ptr_new)
	{
		i = 0;
		while (i < n)
		{
			ptr_new[i] = ptr_old[i];
			i++;
		}
		ptr_new[i] = 0;
		while (i < len)
		{
			buf[i - n] = ptr_old[i];
			i++;
		}
		ft_set_restbuf(buf, len - n);
	}
	free(ptr_old);
	return (ptr_new);
}

char	*get_next_line_loop2(t_cond *cond, t_two_p two_p, char *buf, int len)
{
	int	i;
	int	n;

	i = 0;
	n = ft_find_nl(buf, &((*cond).nl));
	while (i < len)
	{
		two_p.pnew[i] = two_p.pold[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		two_p.pnew[len + i] = buf[i];
		i++;
	}
	two_p.pnew[len + i] = 0;
	while (i < BUFFER_SIZE)
	{
		buf[i - n] = buf[i];
		i++;
	}
	ft_set_restbuf(buf, i - n);
	(*cond).reads++;
	return (two_p.pnew);
}

char	*get_next_line_loop(t_cond *cond, t_two_p two_p, char *buf, int fd)
{
	t_2i	duo_int;

	(*cond).numbyt = read(fd, buf, BUFFER_SIZE);
	if ((*cond).numbyt == -1 || ((*cond).numbyt == 0 && (*cond).reads == 0))
	{
		if (two_p.pnew)
			free(two_p.pnew);
		ft_set_restbuf(buf, 0);
		return (NULL);
	}
	ft_set_restbuf(buf, (*cond).numbyt);
	duo_int.i = ft_find_nl(buf, &((*cond).nl));
	duo_int.len = 0;
	if (two_p.pnew)
	{
		two_p.pold = ft_cpy_new_to_old(two_p.pnew, &(duo_int.len));
		if (!(two_p.pold))
			return ((*cond).nl = 1, NULL);
	}
	two_p.pnew = malloc((duo_int.len + duo_int.i + 1) * sizeof(char));
	if (two_p.pnew)
		two_p.pnew = get_next_line_loop2(cond, two_p, buf, duo_int.len);
	if (two_p.pold)
		free(two_p.pold);
	return (two_p.pnew);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	int			n;
	t_cond		cond;
	t_two_p		two_p;

	cond.reads = 0;
	cond.nl = 0;
	cond.numbyt = BUFFER_SIZE;
	two_p.pold = NULL;
	two_p.pnew = ft_first_assign_new(buf, &(cond.reads));
	n = ft_find_nl(two_p.pnew, &(cond.nl));
	if (two_p.pnew && cond.nl == 1)
		return (ft_return_new_with_nl(two_p.pold, two_p.pnew, n, buf));
	while (cond.numbyt == BUFFER_SIZE && cond.nl == 0)
		two_p.pnew = get_next_line_loop(&cond, two_p, buf, fd);
	return (two_p.pnew);
}

/* int main(void)
{
	int fd1;
	//int fd2;
	//int fdempty;
	char *ptr;
	int i;

	//printf("%i", BUFFER_SIZE);
	fd1 = open("./actions.txt", O_RDONLY);
	//fd1 = open("./test2.txt", O_RDONLY);
	i = 0;
	ptr = get_next_line(fd1);
	printf("\nline %i is:%s", i, ptr);
	i++;
	while (ptr)//(i < 10)
	{
		free (ptr);
		ptr = get_next_line(fd1);
		printf("\nline %i is:%s", i, ptr);
		i++;
	}
	if (ptr)
		free(ptr);
	close(fd1);
} */