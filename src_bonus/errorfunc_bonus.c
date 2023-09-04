/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorfunc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:48:50 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/01 09:53:44 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	ft_errexit(char *errormessage)
{
	write(2, "Error\nCub3d: ", ft_strlen("Error\nCub3d: "));
	ft_putendl_fd(errormessage, 2);
	exit(1);
}

void	ft_errfreeexit(char *errormessage, t_cub_info *info)
{
	ft_free_info(info);
	ft_errexit(errormessage);
}
