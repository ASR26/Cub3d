/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:10:27 by ysmeding          #+#    #+#             */
/*   Updated: 2023/05/15 15:30:26 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_cond
{
	int	nl;
	int	numbyt;
	int	reads;
}		t_cond;

typedef struct s_two_p
{
	char	*pold;
	char	*pnew;
}			t_two_p;

typedef struct s_2i
{
	int	i;
	int	len;
}			t_2i;

char	*get_next_line(int fd);
char	*ft_cpy_new_to_old(char *ptr_new, int *len);
char	*ft_first_assign_new(char buf[BUFFER_SIZE], int *reads);
int		ft_find_nl(char *str, int *nl);
void	ft_set_restbuf(char *buf, int i);
char	*ft_return_new_with_nl(char *ptr_old, char *ptr_new, int n, char *buf);
char	*get_next_line_loop2(t_cond *cond, t_two_p two_p, char *buf, int len);
char	*get_next_line_loop(t_cond *cond, t_two_p two_p, char *buf, int fd);

#endif